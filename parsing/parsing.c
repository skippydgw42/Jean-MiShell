/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:32:20 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/05/05 15:30:26 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

char	**ft_parsing(char *str)
{
	int	q;
	int	i;
	int	j;
	int	k;
	char	**args;

	q = 0;
	i = 0;
	j = 0;
	k = ft_nargs(str, q);
	args = malloc(sizeof(char *) * (k + 1));
	while (j < k)
	{
		args[j] = ft_subcpy(&str[i], q);
		i = ft_strlen(args[j]) + i + 1;
		j++;
	}
	args[j] = 0;
	return (args);
}
