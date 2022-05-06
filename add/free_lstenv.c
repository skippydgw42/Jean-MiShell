/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lstenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 12:09:52 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/05/06 08:30:11 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

int	ft_free_lstenv(t_data *data)
{
	t_env	*ptr;

	while (data->lstenv)
	{
		ptr = data->lstenv;
		if (ptr->varname)
			free(ptr->varname);
		if (ptr->value)
			free(ptr->value);
		data->lstenv = data->lstenv->next;
		free(ptr);
	}
	free(data);
	return (EXIT_SUCCESS);
}
