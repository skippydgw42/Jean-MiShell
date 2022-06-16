/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delnodes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:55:14 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/06/16 15:09:10 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

int	ft_countsize(t_data *data)
{
	int	i;

	i = 0;
	while (data->lstargs)
	{
		i++;
		data->lstargs = data->lstargs->next;
	}
	return (i);
}

int	ft_delnodes(t_data *data)
{
	t_args	*ptr;

	while (data->lstargs)
	{
		ptr = data->args_start;
		if (ft_strlen(data->args_start->str) == 0)
		{
			ptr = data->args_start->next;
			ft_freenode(data->args_start);
			data->args_start = ptr;
			data->lstargs = data->args_start;
		}
		else if (ft_strlen(data->lstargs->str) == 0)
		{
			while (ptr->next != data->lstargs)
				ptr = ptr->next;
			ptr->next = data->lstargs->next;
			ft_freenode(data->lstargs);
			data->lstargs = ptr;
		}
		else
			data->lstargs = data->lstargs->next;
	}
	data->lstargs = data->args_start;
	return (ft_countsize(data));
}
