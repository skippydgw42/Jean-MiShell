/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:20:46 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/06/01 10:12:06 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

static	int	p_error(char *str)
{
	write(2, str, ft_strlen(str));
	return (false);
}

int	ft_init_pipe(t_pipex *vars)
{
	int	i;

	i = 0;
	while (i < vars->nb_pipe)
	{
		if (pipe(&vars->pipe_array[i * 2]) == -1)
			return (p_error("Pipe Construction Failed"));
		i++;
	}
	return (true);
}
