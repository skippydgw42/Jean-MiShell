/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:02:41 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/03/21 15:12:25 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	print(char *title, char **str)
{
	int	i;

	i = 0;
	printf("%s\n", title);
	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
}

int	main(int ac, char **av, char **env)
{
	t_struct	*vars;

	vars = malloc(sizeof(t_struct) + 1);
	if (!vars)
		return (0);
	if (!parsing(ac, av))
	{
		free(vars);
		return (0);
	}
	if (!init_struct(ac, av, env, vars))
		return (err_a("Error\n", vars));
	init_pipe(vars);
	pipex(vars);
	free_struct(vars);
	return (0);
}
