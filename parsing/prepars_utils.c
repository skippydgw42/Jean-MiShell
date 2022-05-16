/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepars_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:29:25 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/05/16 14:07:28 by mdegraeu         ###   ########.fr       */
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
		else if (c == '\'')
			q = 2;
	}
	else if (q == 2)
	{
		if (c == '\"')
			q = 0;
		else if (c == '\"')
			q = 1;
	}
	return (q);
}

int	ft_nargs(char *str, int q)
{
	int	i;
	int	ct;

	i = 0;
	ct = 1;
	while (str[i] == ' ' && ft_quotes(str[i], q) == 0)
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		q = ft_quotes(str[i], q);
		if (q == 0 && str[i] == ' ')
		{
			while (str[i] && str[i] == ' ')
				i++;
			if (str[i])
				ct++;
		}
		else
			i++;
	}
	return (ct);
}

int	ft_sublen(char *str, int q)
{
	int	i;

	i = 0;
	while (str[i])
	{
		q = ft_quotes(str[i], q);
		if (q == 0 && str[i] == ' ')
		{
			while (ft_quotes(str[i], q) == 0 && str[i] == ' ')
				i++;
			break ;
		}
		i++;
	}
	return (i);
}

char	*ft_subcpy(char *str, int q)
{
	int		i;
	int		j;
	char	*dst;

	i = 0;
	j = 0;
	dst = malloc(sizeof(char) * (ft_sublen(str, q) + 1));
	while (str[i])
	{
		q = ft_quotes(str[i], q);
		if (q == 0 && str[i] == ' ')
		{
			i++;
			break ;
		}
		dst[j] = str[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (dst);
}
