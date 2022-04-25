/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:58:35 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/04/25 16:24:46 by mdegraeu         ###   ########.fr       */
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
	ft_looplst(data);
	while (data->lstenv->next != data->start)
	{
		printf("%s\n", data->lstenv->varName);
		data->lstenv = data->lstenv->next;
	}
	ft_free_lstenv(data);
	return (0);
}
