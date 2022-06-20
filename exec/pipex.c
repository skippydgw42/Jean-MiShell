/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:12:35 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/06/20 14:54:20 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

static int	ft_pipe_child(t_data *data, t_pipex *vars)
{
	if (!ft_files(data, vars))
	{
		perror("Error");
		exit(0);
	}
	ft_set_signal_child();
	ft_pipexec(vars, data);
	return (true);
}

static int	ft_pipe_parent(t_pipex *vars)
{
	if (vars->i > 0 && vars->pipe_array[vars->i * 2 - 2] > 2)
	{
		close(vars->pipe_array[vars->i * 2 - 2]);
		close(vars->pipe_array[vars->i * 2 - 1]);
	}
	return (true);
}

static void	ft_waitpid(t_pipex *vars, int *arr_pid)
{
	int	status;

	status = 0;
	vars->i = 0;
	while (vars->i <= vars->nb_pipe)
	{
		waitpid(arr_pid[vars->i], &status, 0);
		if (WIFSIGNALED(status))
		{
			if (g_val_rtn == 131)
				printf("Quit: 3\n");
			else if (g_val_rtn == 130)
				printf("\n");
		}
		else
			g_val_rtn = WEXITSTATUS(status);
		if (vars->heredoc_array[vars->i] != 0)
			close(vars->heredoc_array[vars->i]);
		vars->i++;
	}
}

static int	ft_error_fork(t_pipex *vars, int *arr_pid)
{
	perror("Error");
	ft_waitpid(vars, arr_pid);
	free(arr_pid);
	return (false);
}

int	ft_pipex(t_pipex *vars, t_data *data)
{
	pid_t	*arr_pid;

	ft_set_signal_parent();
	vars->i = 0;
	arr_pid = malloc(sizeof(pid_t) * (vars->nb_pipe + 1));
	if (arr_pid == NULL)
		return (false);
	while (vars->i < vars->nb_pipe + 1)
	{
		arr_pid[vars->i] = fork();
		if (arr_pid[vars->i] < 0)
			return (ft_error_fork(vars, arr_pid));
		if (arr_pid[vars->i] == 0)
			ft_pipe_child(data, vars);
		else if (arr_pid[vars->i] > 0)
			ft_pipe_parent(vars);
		vars->i++;
	}
	ft_waitpid(vars, arr_pid);
	free(arr_pid);
	return (true);
}
