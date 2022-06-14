//
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_pipex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:20:36 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/06/10 16:37:52 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

// SECTION SET_ENV

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

char	**ft_set_env(t_data *data)
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

/////////////////////////////////////////////

// SECTION SET_PATH_CMD

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

static char	**ft_split_path(char **env)
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
		perror("Error");
		return (NULL);
	}
	return (list_path);
}

static char	*ft_take_path(char *cmd, char **env)
{
	int		i;
	char	*path;
	char	**list_path;
	char	*ptr;

	i = 0;
	if (ft_strchr(cmd, '/'))
		return (NULL);
	path = NULL;
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
			ft_free_dstr(list_path);
			return (path);
		}
		free(path);
		i++;
	}
	ft_free_dstr(list_path);
	return (NULL);
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
			{
				if (access(start->str, O_EXCL) == -1)
					perror("Error");
				rtn[i] = ft_strdup(start->str);

				type[i] = EXEC_P;
			}
		}
		if (start->flag == BUILT_F)
		{
			if (ft_strcmp(start->str, "echo") == 0)
				type[i] = BUILT_ECHO_P;
			if (ft_strcmp(start->str, "cd") == 0)
				type[i] = BUILT_CD_P;
			if (ft_strcmp(start->str, "pwd") == 0)
				type[i] = BUILT_PWD_P;
			if (ft_strcmp(start->str, "export") == 0)
				type[i] = BUILT_EXPORT_P;
			if (ft_strcmp(start->str, "unset") == 0)
				type[i] = BUILT_UNSET_P;
			if (ft_strcmp(start->str, "env") == 0)
				type[i] = BUILT_ENV_P;
			if (ft_strcmp(start->str, "exit") == 0)
				type[i] = BUILT_EXIT_P;
		}
		if (start->flag == PIPE_F)
			i++;
		start = start->next;
	}
	return (rtn);
}

/////////////////////////////////////////////
// SECTION SET_FLAGS_CMD

int	ft_nb_of_flag(t_args *start)
{
	int		i;
	t_args	*ptr;

	i = 0;
	ptr = start;
	if (ptr->flag == CMD_F || ptr->flag == BUILT_F)
	{
		ptr = ptr->next;
		i++;
	}
	if (!ptr)
		return (i);
	while (ptr)
	{
		if (ptr->flag == PIPE_F)
			break ;
		if (ptr->flag == STR_F)
			i++;
		ptr = ptr->next;
	}
	return (i);
}

char	***ft_get_flags_cmd(t_data *data, int nb_cmd)
{
	int		i;
	int		j;
	t_args	*start;
	char	***rtn;

	i = 0;
	start = data->args_start;
	rtn = ft_calloc(nb_cmd + 1, sizeof(char **));
	if (!rtn)
		return (NULL);
	while (start)
	{
		j = 0;
		if (start->flag == CMD_F || start->flag == BUILT_F)
		{
			if (start->flag == CMD_F)
				rtn[i] = ft_calloc(ft_nb_of_flag(start) + 1, sizeof(char *));
			if (start->flag == BUILT_F)
				rtn[i] = ft_calloc(ft_nb_of_flag(start), sizeof(char *));
			if (!rtn[i])
				return (NULL);
			if (start->flag == CMD_F)
			{
				rtn[i][j] = ft_strdup(start->str);
				j++;
			}
			start = start->next;
			while (start)
			{
				if (start->flag == PIPE_F)
					break ;
				if (start->flag == STR_F)
				{
					rtn[i][j] = ft_strdup(start->str);
					j++;
				}
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

/////////////////////////////////////////////
// SECTION SET FILES

static int	ft_get_type(char *str, int *input_type, int *output_type)
{
	if (ft_strcmp(str, "<") == 0)
	{
		*input_type = INPUT_P;
		return (INPUT_P);
	}
	if (ft_strcmp(str, "<<") == 0)
	{
		*input_type = HEREDOC_P;
		return (HEREDOC_P);
	}
	if (ft_strcmp(str, ">") == 0)
	{
		*output_type = OUTPUT_P;
		return (OUTPUT_P);
	}
	if (ft_strcmp(str, ">>") == 0)
	{
		*output_type = OUTPUT_APPEND_P;
		return (OUTPUT_APPEND_P);
	}
	return (false);
}

t_redic	*ft_get_files(t_data *data, int nb_cmd)
{
	int		i;
	t_redic	*rtn;
	t_args	*start;
	char	*ptr;
	int		type;

	i = 0;
	rtn = ft_calloc(nb_cmd + 1, sizeof(t_redic));
	if (rtn == NULL)
		return (NULL);
	start = data->args_start;
	rtn[i].input_type = 0;
	rtn[i].output_type = 0;
	rtn[i].input_file = NULL;
	rtn[i].output_file = NULL;
	type = 0;
	while (start)
	{
		if (start->flag == REDIR_F || start->flag == HD_F)
		{
			type = ft_get_type(start->str, &rtn[i].input_type,
					&rtn[i].output_type);
			start = start->next;
		}
		if (type == INPUT_P)
		{
			ptr = rtn[i].input_file;
			rtn[i].input_file = ft_strdup(start->str);
			free(ptr);
		}
		if (type == HEREDOC_P)
		{
			ptr = rtn[i].input_file;
			rtn[i].input_file = NULL;
			free(ptr);
		}
		if (type == OUTPUT_P || type == OUTPUT_APPEND_P)
		{
			ptr = rtn[i].output_file;
			rtn[i].output_file = ft_strdup(start->str);
			free(ptr);
		}
		if (start->flag == PIPE_F)
		{
			i++;
			rtn[i].input_type = 0;
			rtn[i].output_type = 0;
			rtn[i].input_file = NULL;
			rtn[i].output_file = NULL;
		}
		start = start->next;
	}
	return (rtn);
}

/////////////////////////////////////////////
// SECTION Init la tableau pour les pipes

int	*ft_init_pipe_array(int nb_pipe)
{
	int	*rtn;
	int	array_size;

	array_size = nb_pipe * 2;
	rtn = ft_calloc(sizeof(int), array_size + 2);
	return (rtn);
}

/////////////////////////////////////////////
// SECTION Init les heredocs

#define BUFFER_SIZE 42

void	ft_read(int fd)
{
	char	buff[BUFFER_SIZE + 1];
	int		i;

	i = 1;
	while (i)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i < 0)
		{
			perror("Error:");
			exit(errno);
		}
		printf("%s\n", buff);
		buff[i] = 0;
	}
}

int	*ft_init_heredoc(t_data *data, int nb_cmd)
{
	int		i;
	int		tmp;
	int		*rtn;
	t_args	*start;

	i = 0;
	rtn = ft_calloc(sizeof(int), nb_cmd);
	if (rtn == NULL)
		return (NULL);
	start = data->args_start;
	while (start)
	{
		if (start->flag == HD_F)
		{
			start = start->next;
			tmp = rtn[i];
			rtn[i] = ft_heredoc(start->str);
			if (tmp != 0)
				close(tmp);
			if (rtn[i] < 0)
				return (NULL);
		}
		if (start == NULL)
			break ;
		if (start->flag == PIPE_F)
			i++;
		start = start->next;
	}
	return (rtn);
}

/////////////////////////////////////////////

t_pipex	*ft_init_struct_pipex(t_data *data)
{
	t_pipex	*rtn;

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
	rtn->cmd_array = malloc(sizeof(t_cmd));
	if (rtn->cmd_array == NULL)
	{
		ft_free_pipex_struct(rtn);
		return (NULL);
	}
	rtn->cmd_array->type = ft_calloc(rtn->nb_pipe + 1, sizeof(int));
	if (rtn->cmd_array->type == NULL)
	{
		ft_free_pipex_struct(rtn);
		return (NULL);
	}
	rtn->cmd_array->path_cmd = ft_get_path_cmd(data, rtn->nb_pipe + 1, rtn->env,
			rtn->cmd_array->type);
	if (rtn->cmd_array->path_cmd == NULL)
	{
		ft_free_pipex_struct(rtn);
		return (NULL);
	}
	// NOTE Init les flags des commandes
	rtn->cmd_array->flags_cmd = ft_get_flags_cmd(data, rtn->nb_pipe + 1);
	if (rtn->cmd_array->flags_cmd == NULL)
	{
		ft_free_pipex_struct(rtn);
		return (NULL);
	}
	// NOTE init les files et redirecion
	rtn->redic_array = ft_get_files(data, rtn->nb_pipe + 1);
	if (rtn->redic_array == NULL)
	{
		ft_free_pipex_struct(rtn);
		return (NULL);
	}
	// NOTE Init array pour les pipes
	rtn->pipe_array = ft_init_pipe_array(rtn->nb_pipe);
	if (rtn->pipe_array == NULL)
	{
		ft_free_pipex_struct(rtn);
		return (NULL);
	}
	// NOTE Init array pour les heredocs
	rtn->heredoc_array = ft_init_heredoc(data, rtn->nb_pipe + 1);
	if (rtn->heredoc_array == NULL)
	{
		ft_free_pipex_struct(rtn);
		return (NULL);
	}
	// // SECTION TESTEUR pour array_redic
	// int i = 0;
	// while (i < rtn->nb_pipe + 1)
	// {
	// 	printf("============ARRAY REDIC===========\n");
	// 	printf("INPUT:\n");
	// 	printf("	type : %d\n", rtn->redic_array[i].input_type);
	// 	printf("	file : %s\n", rtn->redic_array[i].input_file);
	// printf("	heredoc: %d\n", rtn->heredoc_array[i]);
	// 	printf("OUTPUT:\n");
	// 	printf("	type : %d\n", rtn->redic_array[i].output_type);
	// printf("	file : %s\n", rtn->redic_array[i].output_file);
	// i++;
	// }
	// puts("afa");
	rtn->fd_in = 0;
	rtn->fd_out = 0;
	return (rtn);
}
