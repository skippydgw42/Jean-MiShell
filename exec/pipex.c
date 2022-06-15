/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:12:35 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/06/14 17:02:09 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

//void	et initialiser var globale dan l'exec
int	ft_exec_process(t_pipex *vars, t_data *data)
{
	if (vars->cmd_array->type[vars->i] == CMD_P
		|| vars->cmd_array->type[vars->i] == EXEC_P)
	{
		if (execve(vars->cmd_array->path_cmd[vars->i],
					vars->cmd_array->flags_cmd[vars->i],
					vars->env) == -1)
		{
			if (vars->cmd_array->type[vars->i] == CMD_P || vars)
			{
				puts("J.Mishell: Command not found");
				exit(0);
			}
		}
	}
	else
	{
		ft_call_builtins(vars, data, vars->cmd_array->flags_cmd[vars->i]);
	}
	exit(0);
	return (1);
}

int	ft_pipexec(t_pipex *vars, t_data *data)
{
	if (vars->redic_array[vars->i].input_type == 0)
	{
		if (vars->i > 0)
		{
			dup2(vars->pipe_array[vars->i * 2 - 2], STDIN_FILENO);
			close(vars->pipe_array[vars->i * 2 - 1]);
		}
	}
	if (vars->redic_array[vars->i].input_type != 0)
	{
		dup2(vars->fd_in, STDIN_FILENO);
		close(vars->fd_in);
	}
	if (vars->redic_array[vars->i].output_type == 0)
	{
		if (vars->i != vars->nb_pipe)
		{
			dup2(vars->pipe_array[vars->i * 2 + 1], STDOUT_FILENO);
			close(vars->pipe_array[vars->i * 2]);
		}
	}
	if (vars->redic_array[vars->i].output_type != 0)
	{
		dup2(vars->fd_out, STDOUT_FILENO);
		close(vars->fd_out);
	}
	ft_exec_process(vars, data);
	ft_close_pipe(vars);
	return (1);
}

int	ft_pipex(t_pipex *vars, t_data *data)
{
	pid_t	*arr_pid;
	int		status;

	ft_set_signal_parent();
	vars->i = 0;
	arr_pid = malloc(sizeof(pid_t) * (vars->nb_pipe + 1));
	while (vars->i < vars->nb_pipe + 1)
	{
		arr_pid[vars->i] = fork();
		if (arr_pid[vars->i] < 0)
		{
			free(arr_pid);
			return (false);
		}
		if (arr_pid[vars->i] == 0)
		{
			if (ft_files(data, vars) == false)
			{
				perror("Error");
				exit(0);
			}
			ft_set_signal_child();
			ft_pipexec(vars, data);
		}
		else if (arr_pid[vars->i] > 0)
		{
			if (vars->i > 0 && vars->pipe_array[vars->i * 2 - 2] > 2)
			{
				close(vars->pipe_array[vars->i * 2 - 2]);
				close(vars->pipe_array[vars->i * 2 - 1]);
			}
		}
		vars->i++;
	}
	vars->i = 0;
	while (vars->i <= vars->nb_pipe)
	{
		waitpid(arr_pid[vars->i], &status, 0);
		g_val_rtn = WEXITSTATUS(status);
		if (vars->heredoc_array[vars->i] != 0)
			close(vars->heredoc_array[vars->i]);
		vars->i++;
	}
	free(arr_pid);
	return (true);
}
