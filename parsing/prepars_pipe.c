/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepars_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:07:35 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/06/16 17:47:25 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

static void	ft_npipe_help(char *str, int *i, int *x, int *q)
{
	while (str[*i] && str[*i] != '|')
	{
		*q = ft_quotes(str[*i], *q);
		if (str[*i] != ' ')
			*x = 1;
		*i += 1;
	}
}

static int	ft_npipe_hlp(char *str, int *i, int size, int q)
{
	if (*i < size)
	{
		while (str[*i] && (str[*i] == ' ' && ft_quotes(str[*i], q) == 0))
			*i += 1;
	}
	if (*i >= size)
		return (0);
	return (1);
}

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
		ft_npipe_help(str, &i, &x, &q);
		if (q == 0 && str[i] == '|')
			ct = ct + x + 1;
		x = i;
		i++;
		if (!ft_npipe_hlp(str, &i, size, q))
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
	if (!dst)
		return (NULL);
	while (i < len)
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
