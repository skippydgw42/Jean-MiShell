/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:32:20 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/06/15 14:11:49 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

void	ft_presplitpipe(t_args **lstargs, char *str)
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
		new->next = 0;
		if (prev)
			prev->next = new;
		new->str = ft_cpytopipe(&str[i], q);
		i = ft_strlen(new->str) + i;
		if (!*lstargs)
			*lstargs = new;
		prev = new;
		n--;
	}
}

void	ft_postpars(t_data *data)
{
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
	ft_flag(data);
	ft_fourthsplitlst(data);
	if (!ft_parserr(data))
	{
		g_val_rtn = 258;
		return (0);
	}
	return (true);
}
