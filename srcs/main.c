/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:58:35 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/04/25 12:09:35 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

void	ft_text_color(int i)
{
	if (i == 1)
	{
		printf(GREEN);
	}
}

int	main(int ac, char **av, char **env)
{
	// t_data	*data;
	(void)ac;
	(void)av;
	(void)env;

	t_env	*lstenv;

	lstenv = malloc(sizeof(t_env));
	if (!lstenv)
		return (EXIT_FAILURE);
	ft_set_lstenv(env, lstenv);
	ft_free_lstenv(lstenv);
	// data = malloc(sizeof(t_data));
	// ft_prompt(data);
	
	return (0);
}
