/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:29:05 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/04/26 14:42:44 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

int	ft_env(t_data *data)
{
	while (data->lstenv)	
	{
		if (data->lstenv->is_export)
			printf("%s=%s\n", data->lstenv->varName, data->lstenv->value);
		data->lstenv = data->lstenv->next;
	}
	data->lstenv = data->start;
	return (EXIT_SUCCESS);
}
