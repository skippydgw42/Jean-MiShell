/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:47:24 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/05/10 13:43:48 by mdegraeu         ###   ########.fr       */
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
		if (!ft_strcmp(data->lstargs->str, "export"))
		{
			while (data->lstargs)
			{
				ft_export(&data->lstargs->next->str, data);
				data->lstargs = data->lstargs->next;
			}
		}
		else if (!ft_strcmp(data->lstargs->str, "export") && !data->lstargs->next)
		{
			while (data->lstenv)
			{
				printf("%s\n", data->lstenv->value);
				data->lstenv = data->lstenv->next;
			}
		}
		data->lstenv = data->start;
		free(str);
	}
}
