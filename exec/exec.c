/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:50:21 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/05/31 15:24:19 by ltrinchi         ###   ########lyon.fr   */
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
	ft_free_tab_char(list_path);
	return (NULL);
}

char **ft_get_path_cmd(t_data *data, int nb_cmd, char **env)
{
	int		i;
	char	**rtn;
	t_args	*start;

	i = 0;
	rtn = ft_calloc(nb_cmd + 1, sizeof(char *));
	if (rtn == NULL)
		return (NULL);
	start = data->args_start;
	while (start)
	{
		// FIXME Supprimer start->flags == STR_R car ajout a cause d'un bug dans le parsing
		if (start->flag == CMD_F || start->flag == STR_F)
		{
			rtn[i] = ft_take_path(start->str, env);
		}
		if (start->flag == PIPE_F)
		{
			i++;
		}
		start = start->next;
	}
	return (rtn);
}

char	**ft_get_flags_cmd(t_data *data, int nb_cmd)
{
	int		i;
	char	**rtn;
	char	*ptr;
	t_args	*start;

	i = 0;
	rtn = ft_calloc(nb_cmd + 1, sizeof(char *));
	if (rtn == NULL)
		return (NULL);
	start = data->args_start;
	while (start)
	{
		if (start->flag == CMD_F)
		{
			rtn[i] = ft_strdup(start->str);
			start = start->next;
			while (start)
			{
				if (start->flag != STR_F)
					break ;
				ptr = rtn[i];
				rtn[i] = ft_strjoin(rtn[i], start->str);
				free(ptr);
				start = start->next;
			}
		}
		if (!start)
			break ;
		if (start->flag == PIPE_F)
			i++;
		start = start->next;
	}
	return (rtn);
}

t_pipex *ft_init_struct_pipex(t_data *data)
{
	t_pipex *rtn;

	// NOTE Allocation de la memoire pour la struct
	rtn = malloc(sizeof(t_pipex));
	if (rtn == NULL)
		return (rtn);

	// NOTE Init les var d'env
	rtn->env = ft_set_env(data);
	if (rtn->env == NULL)
	{
		ft_free_pipex_struct(rtn);
		return (NULL);
	}

	// NOTE Init le nombre de pipe
	rtn->nb_pipe = ft_nb_of_pipe(data);

	// NOTE	Init les paths vers les commandes
	rtn->path_cmd = ft_get_path_cmd(data, rtn->nb_pipe + 1, rtn->env);
	if (rtn->path_cmd == NULL)
	{
		ft_free_pipex_struct(rtn);
		return (NULL);
	}

	// NOTE Init les flags des commandes
	rtn->flags_cmd = ft_get_flags_cmd(data, rtn->nb_pipe + 1);
	if (rtn->flags_cmd == NULL)
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
	ft_free_pipex_struct(vars);

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
