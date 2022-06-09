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

	i = 1;
	if (str[0] == '-')
	{
		while (str[i] == '-')
			i++;
		if (str[i] != 'n')
			return (0);
		while (str[i] == 'n')
			i++;
		if (str[i] == ' ')
			return (i);
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
		printf("%s", &str[i]);
		if (!i)
			printf("\n");
	}
	else
		printf("\n");
}