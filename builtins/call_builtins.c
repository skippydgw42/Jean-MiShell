/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 08:45:05 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/06/16 16:55:53 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

int	ft_call_builtins(t_pipex *vars, t_data *data, char **cflags)
{
	if (vars->cmd_array->type[vars->i] == BUILT_ECHO_P)
		ft_echo(vars->cmd_array->flags_cmd[vars->i]);
	else if (vars->cmd_array->type[vars->i] == BUILT_CD_P)
		ft_cd(vars->cmd_array->flags_cmd[vars->i], data);
	else if (vars->cmd_array->type[vars->i] == BUILT_PWD_P)
		ft_pwd();
	else if (vars->cmd_array->type[vars->i] == BUILT_EXPORT_P)
		ft_export(cflags, data);
	else if (vars->cmd_array->type[vars->i] == BUILT_UNSET_P)
		ft_unset(cflags, data);
	else if (vars->cmd_array->type[vars->i] == BUILT_ENV_P)
		ft_env(data);
	else if (vars->cmd_array->type[vars->i] == BUILT_EXIT_P)
		ft_exit(cflags);
	return (true);
}
