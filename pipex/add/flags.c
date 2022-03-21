/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:55:34 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/03/09 18:21:58 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**cflags_null(void)
{
	char	**flags;

	flags = malloc(sizeof(char *) * 1);
	if (!flags)
		return (NULL);
	flags[0] = NULL;
	return (flags);
}

char	**get_flags(char *av)
{
	char	**flags;

	if (ft_strlen(av) == 0)
		return (cflags_null());
	flags = ft_split(av, ' ');
	if (!flags)
		return (NULL);
	return (flags);
}
