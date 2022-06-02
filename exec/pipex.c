/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:12:35 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/06/02 12:16:18 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

int	ft_exec_process(t_pipex *vars)
{
	char	**cflags;

	cflags = ft_get_flags(vars->flags_cmd[vars->i]);
	if (!cflags)
		return (ft_errdstr("Flag Error\n", cflags));
	if (execve(vars->path_cmd[vars->i], cflags, vars->env) == -1)
	{
		ft_free_dstr(cflags);
		exit (ft_errdstr("C_Process: Command not found", NULL));
	}
	return (1);
}

int	ft_pipexec(t_pipex *vars)
{
	int	pid;

	if (vars->redic_array->input_type != 0)
	{
		dup2(vars->fd_in, STDIN_FILENO);
		dup2(vars->pipe_array[vars->i * 2 + 1], STDOUT_FILENO);
		close(vars->fd_in);
	}
	if (vars->redic_array->output_type != 0)
	{
		pid = fork();
		if (pid == 0)
		{
			dup2(vars->fd_out, STDOUT_FILENO);
			close(vars->fd_out);
		}
		else
		{
			dup2(vars->pipe_array[vars->i * 2 - 2], STDIN_FILENO);
		}
	}
	if (vars->redic_array->input_type == 0 && vars->redic_array->output_type == 0)
	{
		dup2(vars->pipe_array[vars->i * 2 - 2], STDIN_FILENO);
		dup2(vars->pipe_array[vars->i * 2 + 1], STDOUT_FILENO);
	}
	ft_close_pipe(vars);
	ft_exec_process(vars);
	return (1);
}

static int ft_get_type(char *str)
{
	if (ft_strcmp(str, "<") == 0)
		return (INPUT_P);
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
		if (start->flag == REDIR_F)
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
	int pid;

	vars->i = 0;
	while (vars->i <= vars->nb_pipe)
	{
		pid = fork();
		// TODO Meilleure gestions des erreurs
		if (pid < 0)
			return (false);
		if (pid == 0)
		{
			printf("Childs\n");
			if (ft_files(data, vars) == false )
				perror("Error:");
			ft_pipexec(vars);
		}
		else
		{
			wait(NULL);
		}
		vars->i++;
	}
	return (true);
}
