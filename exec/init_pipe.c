/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:20:46 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/06/21 09:42:46 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

int	ft_init_pipe(t_pipex *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->nb_pipe)
	{
		if (pipe(&vars->pipe_array[i * 2]) == -1)
		{
			j = 0;
			perror("Error");
			while (j < i)
			{
				close(pipe(&vars->pipe_array[j]));
				j++;
			}
			return (false);
		}
		i++;
	}
	return (true);
}
