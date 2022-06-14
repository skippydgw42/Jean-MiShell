/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 08:45:05 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/06/13 11:06:47 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

// TODO GERE LES REDIRECTIONS DE FICHIER

int	ft_call_builtins(t_pipex *vars, t_data *data, char **cflags)
{
	if (vars->cmd_array->type[vars->i] == BUILT_ECHO_P)
	{
		ft_echo(vars->cmd_array->flags_cmd[vars->i]);
	}
	else if (vars->cmd_array->type[vars->i] == BUILT_CD_P)
	{
		// TODO Modifier pour quil prenne char **flags_cmd
		ft_cd(vars->cmd_array->flags_cmd[vars->i][0], data);
	}
	else if (vars->cmd_array->type[vars->i] == BUILT_PWD_P)
	{
		ft_pwd();
	}
	else if (vars->cmd_array->type[vars->i] == BUILT_EXPORT_P)
	{
		ft_export(cflags, data);
		// ft_free_dstr(cflags);
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
	// ft_free_dstr(cflags);
	return (1);
}
