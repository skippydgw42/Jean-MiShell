/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:58:35 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/04/25 16:39:47 by mdegraeu         ###   ########.fr       */
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
	t_data	*data;
	(void)ac;
	(void)av;
	(void)env;

	data = malloc(sizeof(t_data));
	data->lstenv = ft_set_lstenv(env);
	data->start = data->lstenv;
	while (data->lstenv)
	{
		printf("%s\n", data->lstenv->varName);
		data->lstenv = data->lstenv->next;
	}
	data->lstenv = data->start;
	ft_free_lstenv(data);
	return (0);
}
