/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:47:24 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/05/05 16:45:44 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

void	ft_prompt(void)
{
	char *str;
	t_data *data;

	while (1)
	{
		str = readline(GREEN "Jean_MiShell>> " WHITE);
		if (ft_strlen(str))
			add_history(str);
		if (!ft_parsing(data, str))
			printf("error\n");
		free(str);
	}
}
