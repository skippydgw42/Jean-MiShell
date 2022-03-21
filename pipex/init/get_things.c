/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_things.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:19:39 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/03/09 18:23:09 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	get_files(char **av, t_struct *vars)
{
	int	i;

	i = 0;
	vars->files = malloc(sizeof(char *) * 3);
	if (!vars->files)
		return (0);
	vars->files[0] = ft_strdup(av[i + 1]);
	while (i < vars->ac)
		i++;
	vars->files[1] = ft_strdup(av[i]);
	vars->files[2] = 0;
	if (!vars->files[0] || !vars->files[1])
		return (0);
	return (1);
}

int	get_paths(char **env, t_struct *vars)
{
	int	i;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	vars->env = ft_split(&env[i][5], ':');
	if (!vars->env)
		return (0);
	return (1);
}
