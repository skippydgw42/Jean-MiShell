/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:20:36 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/05/23 14:35:31 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

int	ft_ctpipes(t_data *data)
{
	int	ct;

	ct = 0;
	while (data->lstargs)
	{
		if (data->lstargs->flag == PIPE_F)
			ct++;
		data->lstargs = data->lstargs->next;
	}
	data->lstargs = data->args_start;
	return (ct);
}

int	init_struct(t_data *data, t_pipex *vars)
{
	vars->i = 0;
	vars->nb_pipe = ft_ctpipes(data);
	vars->arr_size = vars->nb_pipe * 2;
	vars->p_cmd = malloc(sizeof(char *) * (vars->));
	if (!vars->p_cmd)
		return (0);
	if (!paths_cmd(vars))
		return (0);
	vars->array = malloc(sizeof(int) * (vars->arr_size));
	if (!vars->array)
		return (0);
	return (1);
}