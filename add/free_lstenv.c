/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lstenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 12:09:52 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/04/25 16:25:33 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

int	ft_free_lstenv(t_data *data)
{
	t_env	*ptr;

	while (data->lstenv->next != data->start)
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
