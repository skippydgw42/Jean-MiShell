/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:15:37 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/06/20 11:11:04 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

void	ft_close_pipe(t_pipex *vars)
{
	int	i;

	i = 0;
	while (i <= vars->nb_pipe)
	{
		if (vars->pipe_array[i] > 2)
			close(vars->pipe_array[i]);
		i++;
	}
}

char	**ft_cflags_null(void)
{
	char	**flags;

	flags = malloc(sizeof(char *) * 1);
	if (!flags)
		return (NULL);
	flags[0] = NULL;
	return (flags);
}

char	**ft_get_flags(char *av)
{
	char	**flags;

	if (ft_strlen(av) == 0)
		return (ft_cflags_null());
	flags = ft_split(av, ' ');
	if (!flags)
		return (NULL);
	return (flags);
}
