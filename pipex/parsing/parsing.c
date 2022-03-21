/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:05:47 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/03/18 12:49:03 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	check_files(char **av)
{
	int	i;

	i = 0;
	if (!av[1] || access(av[1], F_OK) == -1 || access(av[1], R_OK) == -1)
		return (p_error(av[1]));
	while (av[i + 1])
		i++;
	if (access(av[i], F_OK) == 0)
		if (access(av[i], W_OK) == -1)
			return (p_error(av[i]));
	return (1);
}

int	parsing(int ac, char **av)
{
	if (ac < 5)
		return (p_error("Bad Args Count"));
	if (!check_files(av))
		return (0);
	return (1);
}
