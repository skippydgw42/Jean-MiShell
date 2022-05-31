/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:50:21 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/05/31 11:39:20 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

static int	ft_size_lst_env(t_data *data)
{
	int		i;
	t_env	*start;

	i = 0;
	start = data->env_start;
	while (start)
	{
		i++;
		start = start->next;
	}
	return (i);
}

char **ft_set_env(t_data *data)
{
	char	**rtn;
	char	*ptr;
	t_env	*start;
	int		i;

	rtn = ft_calloc(ft_size_lst_env(data) + 1, sizeof(char *));
	if (rtn == NULL)
		return (rtn);
	start = data->env_start;
	i = 0;
	while (start)
	{
		rtn[i] = ft_strjoin(start->varname, "=");
		ptr = rtn[i];
		rtn[i] = ft_strjoin(rtn[i], start->value);
		free(ptr);
		i++;
		start = start->next;
	}
	return (rtn);
}

static	char	**ft_split_path(char **env)
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

static	char	*ft_take_path(char *cmd, char **env)
{
	int		i;
	char	*path;
	char	**list_path;
	char	*ptr;

	i = 0;
	list_path = ft_split_path(env);
	if (list_path == NULL)
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
	return (NULL);
}

char **ft_get_path_cmd(t_data *data, int nb_pipe, char **env)
{
	int		i;
	char	**rtn;
	t_args	*start;

	i = 0;
	rtn = ft_calloc(nb_pipe + 1, sizeof(char *));
	if (rtn == NULL)
		return (NULL);
	start = data->args_start;
	while (start)
	{
		if (start->flag == CMD_F)
		 {
			printf("%d:%s\n", i, ft_take_path(start->str,env));
		 }
		if (start->flag == PIPE_F)
			i++;
		start = start->next;
	}
	return (rtn);
}

t_pipex *ft_init_struct_pipex(t_data *data)
{
	t_pipex *rtn;

	rtn = malloc(sizeof(t_pipex));
	if (rtn == NULL)
		return (rtn);
	
	rtn->env = ft_set_env(data);
	if (rtn->env == NULL)
	{
		ft_free_pipex_struct(rtn);
		return (NULL);
	}
	rtn->nb_pipe = ft_nb_of_pipe(data);
	rtn->path_cmd = ft_get_path_cmd(data, rtn->nb_pipe, rtn->env);
	if (rtn->path_cmd == NULL)
	{
		ft_free_pipex_struct(rtn);
		return (NULL);
	}
	return (rtn);
}

int ft_exec(t_data *data)
{
	t_pipex *vars;

	// TODO initialiser la structures
	
	vars = ft_init_struct_pipex(data);
	if (vars == NULL)
		return (false);


	// TODO Initialiser les pipes
	// ft_init_pipex();

	// TODO Recuperation tous les heredocs
	// ft_heredoc();

	// TODO Execution des commandes
	// TODO Gestion des redirections
	// ft_pipex();

	// TODO Free de la structure pipex
	// ft_free_struct();

	return (true);
}
