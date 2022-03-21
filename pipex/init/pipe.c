/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:06:03 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/03/21 15:04:06 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	init_pipe(t_struct *vars)
{
	int	i;

	i = 0;
	while (i < vars->nb_pipe)
	{
		if (pipe(&vars->array[i * 2]) == -1)
			return (p_error("Pipe Construction Failed"));
		i++;
	}
	return (1);
}
