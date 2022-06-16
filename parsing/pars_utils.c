/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:42:35 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/06/16 17:44:20 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

int	ft_quotes(char c, int q)
{
	if (q == 0)
	{
		if (c == '\'')
			q = 1;
		else if (c == '\"')
			q = 2;
	}
	else if (q == 1)
	{
		if (c == '\'')
			q = 0;
	}
	else if (q == 2)
	{
		if (c == '\"')
			q = 0;
	}
	return (q);
}

int	ft_is_close(char *str)
{
	int	i;
	int	q;

	i = 0;
	q = 0;
	while (str[i])
	{
		q = ft_quotes(str[i], q);
		i++;
	}
	return (q);
}
