/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:21:15 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/06/16 17:37:59 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

static int	ft_check_flag(char *str)
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

void	ft_echo(char **str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (i > 0 && n != i)
			write(1, " ", 1);
		if (ft_check_flag(str[i]) && n == i)
			n++;
		else
			write(1, str[i], ft_strlen(str[i]));
		i++;
	}
	if (i == 0 || n == 0)
		write(1, "\n", 1);
	g_val_rtn = 0;
}
