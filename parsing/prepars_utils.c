/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepars_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:29:25 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/06/16 17:49:44 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

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

int	ft_subcpy(t_args *new, char *str)
{
	int	len;
	int	i;

	i = 0;
	len = ft_sublen(str);
	new->str = malloc(sizeof(char) * (len + 1));
	if (!new->str)
		return (false);
	while (i < len)
	{
		new->str[i] = str[i];
		i++;
	}
	new->str[i] = '\0';
	return (true);
}

static void	ft_splitlst_help(t_args *lstargs, int *i, int *q)
{
	while (lstargs->str[*i])
	{
		*q = ft_quotes(lstargs->str[*i], *q);
		if (*q == 0 && lstargs->str[*i] == ' ')
		{
			while (lstargs->str[*i] == ' ')
				*i += 1;
			break ;
		}
		*i += 1;
	}
}

int	ft_splitlst(t_args *lstargs, int n)
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
		if (!new)
			return (false);
		ft_splitlst_help(lstargs, &i, &q);
		ft_subcpy(new, &lstargs->str[i]);
		new->next = buff->next;
		buff->next = new;
		buff = new;
		n--;
	}
	ft_replacestr(lstargs);
	return (true);
}

void	ft_secondsplitlst(t_data *data)
{
	int	needsplit;

	while (data->lstargs)
	{
		needsplit = ft_needsplit(data->lstargs->str);
		if (needsplit)
			ft_splitlst(data->lstargs, needsplit);
		else
		{
			ft_delspace(data->lstargs);
			data->lstargs = data->lstargs->next;
		}
	}
	data->lstargs = data->args_start;
	while (data->lstargs)
	{
		data->lstargs->flag = ft_piperedir_flags(data->lstargs->str);
		data->lstargs = data->lstargs->next;
	}
	data->lstargs = data->args_start;
}
