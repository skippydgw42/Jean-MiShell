/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 10:22:28 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/06/15 11:06:40 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

static int	ft_size_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (i);
	while (tab[i])
		i++;
	return (i);
}

static int	ft_isallnum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}


void	ft_exit(char **cflags)
{
	int	size_tab;

	size_tab = ft_size_tab(cflags);
	if (size_tab >= 1)
	{
		if (ft_atoi(cflags[0]) == 0 || ft_atoi(cflags[0]) == -1
			|| !ft_isallnum(cflags[0]))
		{
			g_val_rtn = 255;
			printf("%s : numeric argument required", cflags[0]);
		}
		else
		{
			g_val_rtn = (unsigned char)ft_atoi(cflags[0]);
		}
	}
	printf("exit\n");
	if (size_tab > 1)
		printf("Jean_MiShell: exit: too many arguments\n");
	exit(g_val_rtn);
}