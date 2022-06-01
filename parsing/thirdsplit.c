/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thirdsplit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:15:40 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/06/01 13:55:12 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

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
		{
			while (str[i])
			{
				q = ft_quotes(str[i], q);
				if (q == 0 && (str[i] == '>' || str[i] == '<'))
					break ;
				i++;
			}
		}
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
		while (str[i])
		{
			q = ft_quotes(str[i], q);
			if (q == 0 && (str[i] == '>' && str[i] == '<'))
				break ;
			i++;
		}
	new->str = malloc(sizeof(char) * (i + 1));
	while (cpy < i)
	{
		new->str[cpy] = str[cpy];
		cpy++;
	}
	new->str[cpy] = '\0';
	return (cpy);
}

void	ft_majlstargs(t_args *lstargs)
{
	int		i;
	int		cpy;
	char	*dst;

	i = 0;
	cpy = 0;
	if (lstargs->str[i] == '>' || lstargs->str[i] == '<')
		while (lstargs->str[i] == '>' || lstargs->str[i] == '<')
			i++;
	else
		while (lstargs->str[i] != '>' && lstargs->str[i] != '<')
			i++;
	dst = malloc(sizeof(char) * (i + 1));
	while (cpy < i)
	{
		dst[cpy] = lstargs->str[cpy];
		cpy++;
	}
	dst[cpy] = '\0';
	free(lstargs->str);
	lstargs->str = dst;
}

void	ft_splitbyredir(t_args *lstargs, int n)
{
	int		i;
	t_args	*new;
	t_args	*buff;

	i = 0;
	buff = lstargs;
	if (lstargs->str[i] == '>' || lstargs->str[i] == '<')
		while (lstargs->str[i] == '>' || lstargs->str[i] == '<')
			i++;
	else
		while (lstargs->str[i] != '>' && lstargs->str[i] != '<')
			i++;
	while (n && lstargs->str[i])
	{
		new = malloc(sizeof(t_args));
		i = i + ft_setnew(new, &lstargs->str[i]);
		new->next = buff->next;
		buff->next = new;
		buff = new;
		n--;
	}
	ft_majlstargs(lstargs);
}

int	ft_needrsplit(t_args *lstargs)
{
	int	i;
	int	q;

	while (lstargs->str[i])
	{
		q = ft_quotes(lstargs->str[i], q);
		while (q == 0 && (lstargs->str[i] == '>' || lstargs->str[i] == '<'))
			i++;
		if (!lstargs->str[i])
			return (0);
		else
			return (1);
		while (lstargs->str[i] && lstargs->str[i] != '>' && lstargs->str[i] != '<')
			i++;
		if (lstargs->str[i])
			return (1);
		else
			return (0);
	}
	return (0);
}

void	ft_thirdsplitlst(t_data *data)
{
	int	n;

	while (data->lstargs)
	{
		if (ft_needrsplit(data->lstargs))
		{
			n = ft_nredirsplit(data->lstargs->str);
			if (n)
				ft_splitbyredir(data->lstargs, n);
		}
		data->lstargs->flag = ft_piperedir_flags(data->lstargs->str);
		data->lstargs = data->lstargs->next;
	}
	data->lstargs = data->args_start;
}