/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipexec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 13:11:56 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/06/21 14:10:24 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

static int	ft_err_msg(char *str, int type)
{
	if (type == 1)
	{
		ft_putstr_fd("Error: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": Command not found\n", 2);
		return (127);
	}
	else
	{
		ft_putstr_fd("Error: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		return (127);
	}
}

static int	ft_exec_process(t_pipex *vars, t_data *data)
{
	if (vars->cmd_array->type[vars->i] == CMD_P
		|| vars->cmd_array->type[vars->i] == EXEC_P)
	{
		if (execve(vars->cmd_array->path_cmd[vars->i],
				vars->cmd_array->flags_cmd[vars->i],
				vars->env) == -1)
		{
			if (vars->cmd_array->type[vars->i] == CMD_P)
				exit(ft_err_msg(vars->cmd_array->path_cmd[vars->i], 1));
			if (vars->cmd_array->type[vars->i] == EXEC_P)
				exit(ft_err_msg(vars->cmd_array->path_cmd[vars->i], 0));
		}
	}
	else
		ft_call_builtins(vars, data, vars->cmd_array->flags_cmd[vars->i]);
	exit(g_val_rtn);
	return (1);
}

static void	ft_dup2_close(int fd_1, int fd_2, int fd_3)
{
	dup2(fd_1, fd_2);
	close(fd_3);
}

int	ft_pipexec(t_pipex *vars, t_data *data)
{
	if (vars->redic_array[vars->i].input_type == 0)
	{
		if (vars->i > 0)
			ft_dup2_close(vars->pipe_array[vars->i * 2 - 2], STDIN_FILENO,
				vars->pipe_array[vars->i * 2 - 1]);
	}
	if (vars->redic_array[vars->i].input_type != 0)
		ft_dup2_close(vars->fd_in, STDIN_FILENO, vars->fd_in);
	if (vars->redic_array[vars->i].output_type == 0)
	{
		if (vars->i != vars->nb_pipe)
			ft_dup2_close(vars->pipe_array[vars->i * 2 + 1], STDOUT_FILENO,
				vars->pipe_array[vars->i * 2]);
	}
	if (vars->redic_array[vars->i].output_type != 0)
	{
		ft_dup2_close(vars->fd_out, STDOUT_FILENO, vars->fd_out);
	}
	ft_exec_process(vars, data);
	ft_close_pipe(vars);
	return (1);
}
