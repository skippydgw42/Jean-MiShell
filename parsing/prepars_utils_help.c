/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepars_utils_help.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:17:19 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/06/16 14:30:34 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

int	ft_needsplit_help(char *str, int *i)
{
	int	ct;

	ct = 0;
	if (str[*i] == ' ')
	{
		while (str[*i] == ' ')
			*i += 1;
	}
	else
		*i += 1;
	if (str[*i])
		ct++;
	return (ct);
}

int	ft_needsplit(char *str)
{
	int	i;
	int	ct;
	int	q;

	i = 0;
	ct = 0;
	q = 0;
	while (str[i])
	{
		q = ft_quotes(str[i], q);
		if (q == 0 && str[i] == ' ')
			ct += ft_needsplit_help(str, &i);
		else
			i++;
	}
	return (ct);
}

int	ft_replacestr(t_args *lstargs)
{
	int		i;
	int		len;
	char	*dst;

	i = 0;
	len = ft_sublen(lstargs->str);
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (false);
	while (i < len)
	{
		dst[i] = lstargs->str[i];
		i++;
	}
	dst[i] = '\0';
	free(lstargs->str);
	lstargs->str = dst;
	return (true);
}

void	ft_delspace_help(char *dst, char *str, int i)
{
	int	j;

	j = 0;
	j = 0;
	while (j < i)
	{
		dst[j] = str[j];
		j++;
	}
	dst[j] = '\0';
}

int	ft_delspace(t_args *lstargs)
{
	int		i;
	int		q;
	char	*dst;

	i = 0;
	q = 0;
	while (lstargs->str[i])
	{
		q = ft_quotes(lstargs->str[i], q);
		if (q == 0 && lstargs->str[i] == ' ')
			break ;
		i++;
	}
	dst = malloc(sizeof(char) * (i + 1));
	if (!dst)
		return (false);
	ft_delspace_help(dst, lstargs->str, i);
	free(lstargs->str);
	lstargs->str = dst;
	return (true);
}
