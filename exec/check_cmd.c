/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:33:33 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/05/31 10:34:41 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./inclds/JeanMiShell.h"

static void	ft_free_all(char **cmd, char *path_cmd)
{
	ft_free_tab_char(cmd);
	free(path_cmd);
}

static	void	ft_error_msg_cmd(char *cmd, char **list_path)
{
	ft_putstr_fd("zsh: command not found: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd("\n", 2);
	ft_free_tab_char(list_path);
}

static	char	**ft_take_path(char **env)
{
	char	**list_path;
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", ft_strlen(env[i])))
			break ;
		i++;
	}
	list_path = ft_split(&env[i][ft_strlen("PATH=")], ':');
	if (!list_path)
	{
		perror("Error");
		return (NULL);
	}
	return (list_path);
}

static char	*ft_found_cmd(char *cmd, char **env)
{
	int		i;
	char	*path;
	char	**list_path;
	void	*ptr;

	i = 0;
	list_path = ft_take_path(env);
	if (!list_path)
		return (NULL);
	while (list_path[i])
	{
		path = ft_strjoin("/", cmd);
		ptr = path;
		path = ft_strjoin(list_path[i], path);
		free(ptr);
		if (access(path, X_OK) == 0)
		{
			ft_free_tab_char(list_path);
			return (path);
		}
		i++;
		free(path);
	}
	ft_error_msg_cmd(cmd, list_path);
	return (NULL);
}

int	ft_exec(char *av, char **env)
{
	char	**cmd;
	char	*path_cmd;
	int		error;

	error = 0;
	cmd = ft_split(av, ' ');
	if (!cmd)
		return (ft_error_msg());
	if (access(cmd[0], X_OK) == -1)
	{
		path_cmd = ft_found_cmd(cmd[0], env);
		if (!path_cmd)
		{
			ft_free_tab_char(cmd);
			return (EXIT_FAILURE);
		}
	}
	else
		path_cmd = cmd[0];
	if (execve(path_cmd, cmd, env) == -1)
		error = 1;
	ft_free_all(cmd, path_cmd);
	if (error == 1)
		return (ft_error_msg());
	return (EXIT_SUCCESS);
}
