/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 10:22:28 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/06/16 19:07:33 by ltrinchi         ###   ########lyon.fr   */
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
		{
			return (false);
		}
		i++;
	}
	return (true);
}

void	ft_exit(char **cflags)
{
	int	size_tab;

	printf("%d\n", ft_atoi(cflags[0]));
	size_tab = ft_size_tab(cflags);
	if (size_tab >= 1)
	{
		if ((ft_atoi(cflags[0]) == -1 && ft_strlen(cflags[0]) > 2) || (ft_atoi(cflags[0]) == 0 && ft_strlen(cflags[0]) > 0) || ft_isallnum(cflags[0]))
		{
			g_val_rtn = 255;
			printf("Jean_MiShell: exit: %s: numeric argument required\n",
				cflags[0]);
		}
		else
		{
			g_val_rtn = (unsigned char)ft_atoi(cflags[0]);
		}
	}
	if (size_tab > 1)
		printf("Jean_MiShell: exit: too many arguments\n");
	printf("exit\n");
	exit(g_val_rtn);
}
