/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 08:45:05 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/06/09 09:18:30 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

int	ft_call_builtins(t_pipex *vars, t_data *data, char **cflags)
{
	if (vars->cmd_array->type[vars->i] == BUILT_ECHO_P)
	{
		// TODO Gere le flag
		ft_echo(vars->cmd_array->flags_cmd[vars->i], 0);
	}
	else if (vars->cmd_array->type[vars->i] == BUILT_CD_P)
	{
		if (vars->nb_pipe == 0)
			ft_cd(vars->cmd_array->flags_cmd[vars->i], data->lstenv);
	}
	else if (vars->cmd_array->type[vars->i] == BUILT_PWD_P)
	{
		ft_pwd();
	}
	else if (vars->cmd_array->type[vars->i] == BUILT_EXPORT_P)
	{
		ft_export(cflags, data);
	}
	else if (vars->cmd_array->type[vars->i] == BUILT_UNSET_P)
	{
		ft_unset(cflags, data);
	}
	else if (vars->cmd_array->type[vars->i] == BUILT_ENV_P)
	{
		ft_env(data);
	}
	else if (vars->cmd_array->type[vars->i] == BUILT_EXIT_P)
	{
		exit(0);
	}
	return (1);
}
