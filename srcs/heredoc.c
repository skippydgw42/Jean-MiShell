/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:38:54 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/06/15 17:08:50 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

static void	ft_exit_signal(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		signal(SIGINT, ft_signal_handler);
		exit(1);
	}
}

static int	ft_reset_settings_signal(void)
{
	perror("Error");
	signal(SIGINT, ft_signal_handler);
	return (-1);
}

static int	ft_heredoc_child(int fd_pipe[2], char *delimiter)
{
	char	*str;

	signal(SIGINT, ft_exit_signal);
	if (close(fd_pipe[0]) == -1)
		exit(1);
	while (1)
	{
		str = readline(">");
		if (!str)
			exit(0);
		if (ft_strcmp(str, delimiter) == 0)
		{
			close(fd_pipe[1]);
			free(str);
			exit(0);
		}
		ft_putstr_fd(str, fd_pipe[1]);
		ft_putstr_fd("\n", fd_pipe[1]);
		free(str);
	}
}

static int	ft_heredoc_parent(int pid, int fd_pipe[2])
{
	int	rtn;

	rtn = 0;
	if (close(fd_pipe[1]) == -1)
		return (ft_reset_settings_signal());
	waitpid(pid, &rtn, 0);
	signal(SIGINT, ft_signal_handler);
	if (WEXITSTATUS(rtn) == 1)
		return (-1);
	return (fd_pipe[0]);
}

int	ft_heredoc(char *delimiter)
{
	int	fd_pipe[2];
	int	pid;
	int	rtn;

	if (!delimiter || ft_strlen(delimiter) == 0)
	{
		ft_putstr_fd("Jean-MiShell: syntax error near \
			unexpected token `newline'\n",
			STDOUT_FILENO);
		return (-1);
	}
	signal(SIGINT, SIG_IGN);
	rtn = 0;
	if (pipe(fd_pipe) == -1)
		return (ft_reset_settings_signal());
	pid = fork();
	if (pid < 0)
		return (ft_reset_settings_signal());
	if (pid == 0)
		ft_heredoc_child(fd_pipe, delimiter);
	else
		return (ft_heredoc_parent(pid, fd_pipe));
	return (0);
}
