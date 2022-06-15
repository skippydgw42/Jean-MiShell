/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepars_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:07:35 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/06/14 16:25:46 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

int	ft_npipe(char *str)
{
	int	i;
	int	x;
	int	q;
	int	ct;
	int	size;

	i = 0;
	q = 0;
	ct = 0;
	size = ft_strlen(str);
	while (str[i])
	{
		x = 0;
		while (str[i] && str[i] != '|')
		{
			q = ft_quotes(str[i], q);
			if (str[i] != ' ')
				x = 1;
			i++;
		}
		if (q == 0 && str[i] == '|')
			ct = ct + x + 1;
		x = i;
		// if (str[i]) ==> si on l enleve->overflow
		i++;
		// NOTE Truc bizarre que je tente
		if (i < size)
		{
			while (str[i] && (str[i] == ' ' && ft_quotes(str[i], q) == 0))
				i++;
		}
		if (i >= size)
			break ;
	}
	if (x == i - 1 && str[x] != '|')
		ct++;
	return (ct);
}

int	ft_lentopipe(char *str, int q)
{
	int	i;

	i = 0;
	while (str[i])
	{
		q = ft_quotes(str[i], q);
		if (q == 0 && str[i] == '|')
			return (i);
		i++;
	}
	return (i);
}

char	*ft_cpytopipe(char *str, int q)
{
	int		i;
	int		len;
	char	*dst;

	i = 0;
	if (str[i] != '|')
		len = ft_lentopipe(str, q);
	else
		len = 1;
	dst = malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
