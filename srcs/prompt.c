/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:47:24 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/04/25 11:01:31 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

void	ft_prompt(void)
{
	char *str;

	while (1)
	{
		str = readline(GREEN "Jean_MiShell>> " WHITE);
		if (ft_strlen(str))
			add_history(str);
		// ft_cd(str, lstenv);
		free(str);
	}
}
