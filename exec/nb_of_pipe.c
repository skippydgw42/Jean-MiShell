/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_of_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 09:37:53 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/05/31 11:00:21 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

int	ft_nb_of_pipe(t_data *data)
{
	int		i;
	t_args	*start;

	i = 0;
	start = data->args_start;
	while (start)
	{
		if (start->flag == PIPE_F)
			i++;
		start = start->next;
	}
	return (i);
}
