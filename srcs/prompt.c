/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:47:24 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/05/12 13:42:19 by mdegraeu         ###   ########.fr       */
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
		if (!ft_parsing(data, str))
			printf("error\n");
		else if (str == NULL)
		{
			printf("exit\n"); //NOTE Gestion de ctrl-d
			ft_exit(0);
		}
		// ft_export(str, data);
		// if (!ft_parsing(data, str))
			// printf("error\n");
		free(str);
	}
}
