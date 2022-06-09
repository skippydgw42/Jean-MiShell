/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:58:35 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/06/09 11:31:01 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

int	main(int ac, char **av, char **env)
{
	t_data	*data;

	(void)ac;
	(void)av;
	data = malloc(sizeof(t_data));
	if (!data)
	{
		perror("Error:");
		return (errno);
	}
	data->lstenv = ft_set_lstenv(env);
	data->env_start = data->lstenv;
	ft_prompt(data);
	ft_free_data(data);
	return (0);
}
