/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:32:20 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/06/17 14:25:25 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

static int	ft_presplitpipe_help(t_args *new, t_args *prev, char *str, int *i)
{
	int	q;

	q = 0;
	new->next = 0;
	if (prev)
		prev->next = new;
	new->str = ft_cpytopipe(&str[*i], q);
	if (!new->str)
		return (false);
	*i = ft_strlen(new->str) + *i;
	return (true);
}

static int	ft_presplitpipe(t_args **lstargs, char *str)
{
	int		q;
	int		i;
	int		n;
	t_args	*new;
	t_args	*prev;

	q = 0;
	i = 0;
	n = ft_npipe(str);
	prev = NULL;
	while (n)
	{
		while (str[i] == ' ' && ft_quotes(str[i], q) == 0)
			i++;
		new = malloc(sizeof(t_args));
		if (!new)
			return (false);
		if (!ft_presplitpipe_help(new, prev, str, &i))
			return (false);
		if (!*lstargs)
			*lstargs = new;
		prev = new;
		n--;
	}
	return (true);
}

void	ft_postpars(t_data *data)
{
	ft_needsplitvar(data->lstargs);
	while (data->lstargs)
	{
		ft_replace(data, data->lstargs);
		data->lstargs = data->lstargs->next;
	}
	data->lstargs = data->args_start;
}

int	ft_parsing(t_data *data, char *str)
{
	data->lstargs = NULL;
	if (ft_is_close(str))
	{
		g_val_rtn = 258;
		return (ft_errquotes());
	}
	ft_presplitpipe(&data->lstargs, str);
	data->args_start = data->lstargs;
	ft_secondsplitlst(data);
	ft_thirdsplitlst(data);
	ft_postpars(data);
	ft_fourthsplitlst(data);
	ft_flag(data);
	if (!ft_delnodes(data))
		return (false);
	data->lstargs = data->args_start;
	ft_delquotes(data);
	if (!ft_parserr(data))
	{
		g_val_rtn = 258;
		return (0);
	}
	return (true);
}
