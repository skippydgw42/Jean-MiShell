/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:29:25 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/05/05 15:30:22 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

int	ft_quotes(char *str, int q)
{
	if (q == 0)
	{
		if (str[0] == '\'')
			q = 1;
		else if (str[0] == '\"')
			q = 2;
	}
	else if (q == 1)
	{
		if (str[0] == '\'' && (!str[1] || str[1] == ' '))
			q = 0;
		else if (str[0] == '\'' && str[1] == '\"')
			q = 2;
	}
	else if (q == 2)
	{
		if (str[0] == '\"' && (!str[1] || str[1] == ' '))
			q = 0;
		else if (str[0] == '\"' && str[1] == '\'')
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
	while (str[i])
	{
		q = ft_quotes(&str[i], q);
		if (q == 0 && str[i] == ' ')
		{
			ct++;
			while (str[i] && (ft_quotes(&str[i + 1], q) == 0 && str[i] == ' '))
				i++;
		}
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
		q = ft_quotes(&str[i], q);
		if (q == 0 && str[i] == ' ')
		{
			while (ft_quotes(&str[i], q) == 0 && str[i] == ' ')
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
	char	*dst;

	i = 0;
	dst = malloc(sizeof(char) * (ft_sublen(str, q) + 1));
	while (str[i])
	{
		q = ft_quotes(&str[i], q);
		if (q == 0 && str[i] == ' ')
		{
			i++;
			break ;
		}
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
