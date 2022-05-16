/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:47:24 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/05/16 10:27:43 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

void ft_prompt(t_data *data)
{
	char *str;

	while (1)
	{
		str = readline(BLUE "Jean" WHITE "_Mi" RED "Shell>> " WHITE);
		if (ft_strlen(str))
			add_history(str);
		else if (str == NULL)
		{
			printf("exit\n"); // NOTE Gestion de ctrl-d
			ft_exit(0);
		}
		if (!ft_parsing(data, str))
			printf("error\n");
		// ft_export(str, data);
		// if (!ft_parsing(data, str))
		// printf("error\n");
		free(str);
	}
}
