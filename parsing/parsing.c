/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:32:20 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/05/06 14:22:53 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

char	**ft_preparsing(char *str)
{
	int	q;
	int	i;
	int	j;
	int	n;
	char	**args;

	q = 0;
	i = 0;
	j = 0;
	n = ft_nargs(str, q);
	args = malloc(sizeof(char *) * (n + 1));
	while (j < n)
	{
		args[j] = ft_subcpy(&str[i], q);
		i = ft_strlen(args[j]) + i + 1;
		j++;
	}
	args[j] = 0;
	return (args);
}

char	**ft_parsing(t_data *data, char *str)
{
	char	**args;

	if (ft_is_close(str))
		return (NULL);
	args = ft_preparsing(str);
	return (args);
}