/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:58:35 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/05/05 15:33:31 by mdegraeu         ###   ########.fr       */
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

	data = malloc(sizeof(t_data));
	if (!data)
	{
		perror("Error:");
		return (errno);
	}
	data->lstenv = ft_set_lstenv(env);
	data->start = data->lstenv;
	ft_prompt();
	ft_free_lstenv(data);
	return (0);
}
