/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:50:21 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/06/09 09:02:42 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

int ft_exec(t_data *data)
{
	t_pipex *vars;
	char	**cflags;

	// NOTE Init la struct + init des heredocs
	vars = ft_init_struct_pipex(data);
	if (vars == NULL)
		return (false);
	// NOTE Initialiser les pipes
	ft_init_pipe(vars);

	if (vars->nb_pipe == 0 && data->args_start->flag == BUILT_F)
	{
		cflags = ft_get_flags(vars->cmd_array->flags_cmd[vars->i]);
		if (!cflags)
			return (ft_errdstr("Flag Error\n", cflags));
		ft_call_builtins(vars, data, cflags);
	}
	else if (ft_pipex(vars, data) == false)
		perror("Error");

	// NOTE Free la struct de Pipex
	ft_free_pipex_struct(vars);

	return (true);
}
