/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:50:21 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/06/21 10:15:31 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

static int	ft_redic(t_data *data, t_pipex *vars)
{
	if (ft_files(data, vars) == false)
	{
		perror("Error");
		return (false);
	}
	if (vars->redic_array[vars->i].input_type != 0)
	{
		dup2(vars->fd_in, STDIN_FILENO);
		close(vars->fd_in);
	}
	if (vars->redic_array[vars->i].output_type != 0)
	{
		dup2(vars->fd_out, STDOUT_FILENO);
		close(vars->fd_out);
	}
	return (true);
}

static int	ft_exec_help(t_data *data, t_pipex *vars)
{
	int	fd_out;
	int	fd_in;

	fd_out = dup(STDOUT_FILENO);
	fd_in = dup(STDIN_FILENO);
	vars->i = 0;
	if (!ft_redic(data, vars))
		return (false);
	ft_call_builtins(vars, data, vars->cmd_array->flags_cmd[vars->i]);
	dup2(fd_out, STDOUT_FILENO);
	dup2(fd_in, STDIN_FILENO);
	close(fd_out);
	close(fd_in);
	return (true);
}

int	ft_exec(t_data *data)
{
	t_pipex	*vars;

	vars = ft_init_struct_pipex(data);
	if (vars == NULL)
		return (false);
	if (!ft_init_pipe(vars))
	{
		ft_free_pipex_struct(vars);
		return (false);
	}
	if (vars->nb_pipe == 0 && data->args_start->flag == BUILT_F)
	{
		if (!ft_exec_help(data, vars))
			return (false);
	}
	else if (!ft_pipex(vars, data))
	{
		ft_close_pipe(vars);
		ft_free_pipex_struct(vars);
		return (false);
	}
	ft_free_pipex_struct(vars);
	return (true);
}
