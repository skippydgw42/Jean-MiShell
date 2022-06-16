/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thirdsplit_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:38:59 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/06/16 17:50:05 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

static void	ft_nredirsplit_help(char *str, int *i, int *q)
{
	while (str[*i])
	{
		*q = ft_quotes(str[*i], *q);
		if (*q == 0 && (str[*i] == '>' || str[*i] == '<'))
			break ;
		*i += 1;
	}
}

int	ft_nredirsplit(char *str)
{
	int	i;
	int	q;
	int	ct;

	i = 0;
	q = 0;
	ct = 0;
	while (str[i])
	{
		if (q == 0 && (str[i] == '>' || str[i] == '<'))
			while (str[i] && (str[i] == '>' || str[i] == '<'))
				i++;
		else
			ft_nredirsplit_help(str, &i, &q);
		if (str[i])
			ct++;
	}
	return (ct);
}

int	ft_setnew(t_args *new, char *str)
{
	int	i;
	int	q;
	int	cpy;

	i = 0;
	q = 0;
	cpy = 0;
	if (str[i] == '>' || str[i] == '<')
		while (str[i] == '>' || str[i] == '<')
			i++;
	else
		ft_nredirsplit_help(str, &i, &q);
	new->str = malloc(sizeof(char) * (i + 1));
	if (!new->str)
		return (0);
	while (cpy < i)
	{
		new->str[cpy] = str[cpy];
		cpy++;
	}
	new->str[cpy] = '\0';
	return (cpy);
}
