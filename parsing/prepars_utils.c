/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepars_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:29:25 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/05/20 13:53:35 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

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
		{
			while (str[i] == ' ')
				i++;
			if (str[i])
				ct++;
		}
		else
			i++;
	}
	return (ct);
}

int	ft_sublen(char *str)
{
	int	i;
	int	q;

	i = 0;
	q = 0;
	while (str[i])
	{
		q = ft_quotes(str[i], q);
		if (q == 0 && str[i] == ' ')
			return (i);
		i++;
	}
	return (i);
}

void	ft_subcpy(t_args *new, char *str)
{
	int	len;
	int	i;

	i = 0;
	len = ft_sublen(str);
	new->str = malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		new->str[i] = str[i];
		i++;
	}
	new->str[i] = '\0';
}

void	ft_replacestr(t_args *lstargs)
{
	int		i;
	int		len;
	char	*dst;

	i = 0;
	len = ft_sublen(lstargs->str);
	dst = malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		dst[i] = lstargs->str[i];
		i++;
	}
	dst[i] = '\0';
	free(lstargs->str);
	lstargs->str = dst;
}

void	ft_splitlst(t_args *lstargs, int n)
{
	int		i;
	int		q;
	t_args	*new;
	t_args	*buff;

	i = 0;
	q = 0;
	buff = lstargs;
	while (n)
	{
		new = malloc(sizeof(t_args));
		while (lstargs->str[i])
		{
			q = ft_quotes(lstargs->str[i], q);
			if (lstargs->str[i] == ' ' && q == 0)
			{
				while (lstargs->str[i] == ' ')
					i++;
				break ;
			}
			i++;
		}
		ft_subcpy(new, &lstargs->str[i]);
		new->next = buff->next;
		buff->next = new;
		buff = new;
		n--;
	}
	ft_replacestr(lstargs);
}

void	ft_secondsplitlst(t_args *lstargs)
{
	int	needsplit;

	while (lstargs)
	{
		needsplit = ft_needsplit(lstargs->str);
		if (needsplit)
			ft_splitlst(lstargs, needsplit);
		else
			lstargs = lstargs->next;
	}
}