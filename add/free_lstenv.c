/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lstenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 12:09:52 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/04/28 15:28:06 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

int	ft_free_lstenv(t_data *data)
{
	t_env	*ptr;

	while (data->lstenv)
	{
		ptr = data->lstenv;
		if (ptr->varName)
			free(ptr->varName);
		if (ptr->value)
			free(ptr->value);
		data->lstenv = data->lstenv->next;
		free(ptr);
	}
	free(data);
	return (EXIT_SUCCESS);
}
