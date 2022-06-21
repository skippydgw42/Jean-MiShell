/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_path_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:18:06 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/06/21 09:39:19 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

static int	ft_check_path_exist(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", ft_strlen(env[i])))
			return (true);
		i++;
	}
	return (false);
}

static void	ft_set_flag(t_args *start, int *type, int i)
{
	if (start->flag == BUILT_F)
	{
		if (ft_strcmp(start->str, "echo") == 0)
			type[i] = BUILT_ECHO_P;
		else if (ft_strcmp(start->str, "cd") == 0)
			type[i] = BUILT_CD_P;
		else if (ft_strcmp(start->str, "pwd") == 0)
			type[i] = BUILT_PWD_P;
		else if (ft_strcmp(start->str, "export") == 0)
			type[i] = BUILT_EXPORT_P;
		else if (ft_strcmp(start->str, "unset") == 0)
			type[i] = BUILT_UNSET_P;
		else if (ft_strcmp(start->str, "env") == 0)
			type[i] = BUILT_ENV_P;
		else if (ft_strcmp(start->str, "exit") == 0)
			type[i] = BUILT_EXIT_P;
	}
}

static void	ft_set_file(char **rtn, int i, t_args *start, int *type)
{
	rtn[i] = ft_strdup(start->str);
	if (rtn[i] == NULL)
		return ;
	if (ft_strchr(start->str, '/'))
		type[i] = EXEC_P;
}

char	**ft_split_path(char **env)
{
	char	**list_path;
	int		i;

	i = 0;
	if (ft_check_path_exist(env) == false)
		return (NULL);
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", ft_strlen(env[i])))
			break ;
		i++;
	}
	list_path = ft_split(&env[i][ft_strlen("PATH=")], ':');
	if (!list_path)
	{
		perror("Error split path");
		return (NULL);
	}
	return (list_path);
}

char	**ft_get_path_cmd(t_data *data, int nb_cmd, char **env, int *type)
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
		if (start->flag == CMD_F)
		{
			type[i] = CMD_P;
			rtn[i] = ft_take_path(start->str, env);
			if (rtn[i] == NULL)
				ft_set_file(rtn, i, start, type);
		}
		else if (start->flag == BUILT_F)
			ft_set_flag(start, type, i);
		if (start->flag == PIPE_F)
			i++;
		start = start->next;
	}
	return (rtn);
}
