/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:20:46 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/05/23 11:21:08 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

int	ft_init_pipe(t_pipex *vars)
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
