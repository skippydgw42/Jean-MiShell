/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 13:42:35 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/03/09 18:22:03 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	hm_cmd(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
		i++;
	return (i + 1);
}

char	*split_flags(char *av)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (av[i] == ' ' && av[i])
		i++;
	j = i;
	while (av[i] != ' ' && av[i])
		i++;
	str = malloc(sizeof(char) * (i - j + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (av[j] != ' ' && av[j])
	{
		str[i] = av[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
