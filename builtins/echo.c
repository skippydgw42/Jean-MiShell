/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:21:15 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/04/20 19:05:54 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

int	ft_check_flag(char *str)
{
	int	i;
	int	x;

	i = 0;
	while (str[i] && str[0] == '-')
	{
		x = i;
		while (str[i] == '-')
			i++;
		if (str[i] != 'n')
			return (x);
		while (str[i] == 'n')
			i++;
		if (!str[i])
			return (i);
		if (str[i] != ' ')
			return (x);
		while (str[i] == ' ')
			i++;
	}
	return (0);
}

void	ft_echo(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		i = ft_check_flag(str);
		if (str[i])
			printf("%s", &str[i]);
		if (i == 0)
			printf("\n");
	}
	else
		printf("\n");
}
