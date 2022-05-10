/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:47:24 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/05/10 11:36:01 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

void	ft_prompt(t_data *data)
{
	char *str;

	while (1)
	{
		str = readline(GREEN "Jean_MiShell>> " WHITE);
		if (ft_strlen(str))
			add_history(str);
		else if (str == NULL)
		{
			printf("exit\n"); //NOTE Gestion de ctrl-d
			exit(0);
		}
		// ft_export(str, data);
		if (!ft_parsing(data, str))
			printf("error\n");
		free(str);
	}
}
