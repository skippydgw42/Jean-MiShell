/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:29:05 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/06/15 11:07:17 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

int	ft_env(t_data *data)
{
	while (data->lstenv)
	{
		if (data->lstenv->is_export == true)
		{
			if (data->lstenv->value)
				printf("%s=%s\n", data->lstenv->varname, data->lstenv->value);
		}
		data->lstenv = data->lstenv->next;
	}
	data->lstenv = data->env_start;
	g_val_rtn = 0;
	return (EXIT_SUCCESS);
}
