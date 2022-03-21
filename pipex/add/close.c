/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:09:00 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/03/21 15:04:01 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	close_pipe(t_struct *vars)
{
	int	i;

	i = 0;
	while (i < vars->arr_size)
	{
		close(vars->array[i]);
		i++;
	}
}
