/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:12:35 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/06/08 13:59:40 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

//void	et initialiser var globale dan l'exec
int	ft_exec_process(t_pipex *vars, t_data *data)
{
	char	**cflags;
	char	*ptr;
	char	*str;
	int		i;
	
	i = 0;
	str = NULL;
	// FIXME A supprimer une fois le parsing fix
	vars->cmd_array->type[vars->i] = BUILT_ECHO_P;
	cflags = ft_get_flags(vars->cmd_array->flags_cmd[vars->i]);
	if (!cflags)
		return (ft_errdstr("Flag Error\n", cflags));
	if (vars->cmd_array->type[vars->i] == CMD_P)
	{
		cflags = ft_get_flags(vars->cmd_array->flags_cmd[vars->i]);
		if (!cflags)
			return (ft_errdstr("Flag Error\n", cflags));
		if (execve(vars->cmd_array->path_cmd[vars->i], cflags, vars->env) == -1)
		{
			ft_free_dstr(cflags);
			exit(ft_errdstr("C_Process: Command not found", NULL));
		}
	}
	else if (vars->cmd_array->type[vars->i] == BUILT_ECHO_P)
	{
		// FIXME Cest quoi le flag ?
		ft_echo(vars->cmd_array->flags_cmd[vars->i], 0);
		exit(0);
	}
	else if (vars->cmd_array->type[vars->i] == BUILT_CD_P)
	{
		if (vars->nb_pipe == 0)
			ft_cd(vars->cmd_array->flags_cmd[vars->i], data->lstenv);
		exit(0);
	}
	else if (vars->cmd_array->type[vars->i] == BUILT_PWD_P)
	{
		ft_pwd();
		exit(0);
	}
	else if (vars->cmd_array->type[vars->i] == BUILT_EXPORT_P)
	{
		if (vars->nb_pipe == 0)
			ft_export(cflags, data);
		exit(0);
	}
	else if (vars->cmd_array->type[vars->i] == BUILT_UNSET_P)
	{
		if (vars->nb_pipe == 0)
			ft_unset(cflags, data);
		exit(0);
	}
	else if (vars->cmd_array->type[vars->i] == BUILT_ENV_P)
	{
		if (vars->nb_pipe == 0)
			ft_env(data);
		exit(0);
	}
	else if (vars->cmd_array->type[vars->i] == BUILT_EXIT_P)
	{
		exit(0);
	}
	return (1);
}

int ft_pipexec(t_pipex *vars, t_data *data)
{
	if (vars->redic_array[vars->i].input_type == 0) // pas d'input file
	{
		if (vars->i > 0)
		{
			dup2(vars->pipe_array[vars->i * 2 - 2], STDIN_FILENO);
			close(vars->pipe_array[vars->i * 2 - 1]);
		}
	}
	else if (vars->redic_array[vars->i].input_type != 0) // input file
	{
		dup2(vars->fd_in, STDIN_FILENO);
		close(vars->fd_in);
	}
	if (vars->redic_array[vars->i].output_type == 0) // pas d'outfile
	{
		if (vars->i != vars->nb_pipe)
		{
			dup2(vars->pipe_array[vars->i * 2 + 1], STDOUT_FILENO);
			close(vars->pipe_array[vars->i * 2]);
		}
	}
	else if (vars->redic_array[vars->i].output_type != 0) // outfile
	{
		dup2(vars->fd_out, STDOUT_FILENO);
		close(vars->fd_out);
	}
	ft_close_pipe(vars);
	ft_exec_process(vars, data);
	return (1);
}

static int ft_get_type(char *str)
{
	if (ft_strcmp(str, "<") == 0)
		return (INPUT_P);
	if (ft_strcmp(str, "<<") == 0)
		return (HEREDOC_P);
	if (ft_strcmp(str, ">") == 0)
		return (OUTPUT_P);
	if (ft_strcmp(str, ">>") == 0)
		return (OUTPUT_APPEND_P);
	return (false);
}

int ft_files(t_data *data, t_pipex *vars)
{
	int i;
	int type;
	t_args *start;

	i = 0;
	start = data->args_start;
	while (i < vars->i)
	{
		start = start->next;
		if (start->flag == PIPE_F)
			i++;
	}
	while (start)
	{
		if (start->flag == REDIR_F || start->flag == HD_F)
		{
			type = ft_get_type(start->str);
			start = start->next;
			if (type == INPUT_P)
			{
				if (vars->fd_in != 0)
					close(vars->fd_in);
				vars->fd_in = open(start->str, O_RDONLY);
				if (vars->fd_in < 0)
					return (false);
			}
			if (type == HEREDOC_P)
			{
				if (vars->fd_in != 0)
					close(vars->fd_in);
				vars->fd_in = vars->heredoc_array[vars->i];
			}
			if (type == OUTPUT_P)
			{
				if (vars->fd_out != 0)
					close(vars->fd_out);
				vars->fd_out = open(start->str, O_TRUNC | O_WRONLY | O_CREAT, 0666);
				if (vars->fd_out < 0)
					return (false);
			}
			if (type == OUTPUT_APPEND_P)
			{
				if (vars->fd_out != 0)
					close(vars->fd_out);
				vars->fd_out = open(start->str, O_APPEND | O_WRONLY | O_CREAT, 0666);
				if (vars->fd_out < 0)
					return (false);
			}
		}
		start = start->next;
		if (!start || start->flag == PIPE_F)
			break;
	}
	return (true);
}

int ft_pipex(t_pipex *vars, t_data *data)
{
	int *arr_pid;

	vars->i = 0;
	arr_pid = malloc(sizeof(int) * vars->nb_pipe);

	while (vars->i < vars->nb_pipe + 1)
	{
		arr_pid[vars->i] = fork();
		if (arr_pid[vars->i] < 0)
			return (false);
		if (arr_pid[vars->i] == 0)
		{
			if (ft_files(data, vars) == false)
			{
				perror("Error:");
				exit(0);
			}
			ft_pipexec(vars, data);
		}
		else if (vars->i > 0)
		{
			close(vars->pipe_array[vars->i * 2 - 2]);
			close(vars->pipe_array[vars->i * 2 - 1]);
		}
		vars->i++;
	}
	vars->i = 0;
	while (vars->i <= vars->nb_pipe)
	{
		waitpid(arr_pid[vars->i], NULL, 0);
		vars->i++;
	}
	return (true);
}
