/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 12:04:12 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/06/16 17:43:57 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

static int	ft_syntaxerr(t_data *data)
{
	int	i;

	i = 0;
	data->lstargs = data->args_start;
	while (data->lstargs)
	{
		data->lstargs = data->lstargs->next;
		i++;
	}
	data->lstargs = data->args_start;
	if (i == 1 && (data->lstargs->flag != CMD_F
			&& data->lstargs->flag != BUILT_F))
		return (0);
	return (1);
}

static int	ft_redirerr(t_data *data)
{
	int	i;

	while (data->lstargs)
	{
		if (data->lstargs->flag == REDIR_F || data->lstargs->flag == HD_F)
		{
			i = 0;
			if (data->lstargs->next && data->lstargs->next->flag == REDIR_F)
				return (ft_errmsg(data->lstargs->next));
			if (data->lstargs->next && data->lstargs->next->flag == HD_F)
				return (ft_errmsg(data->lstargs->next));
			while (data->lstargs->str[i])
				i++;
			if (i > 2)
				return (ft_errmsg(data->lstargs));
		}
		data->lstargs = data->lstargs->next;
	}
	data->lstargs = data->args_start;
	return (1);
}

int	ft_parserr(t_data *data)
{
	if (data->lstargs->flag == PIPE_F)
		return (ft_errmsg(data->lstargs));
	if (!ft_redirerr(data))
		return (0);
	while (data->lstargs->next)
	{
		if (data->lstargs->flag == PIPE_F)
			if (data->lstargs->next->flag == PIPE_F)
				return (ft_errmsg(data->lstargs));
		data->lstargs = data->lstargs->next;
	}
	if (data->lstargs->flag == PIPE_F || data->lstargs->flag == REDIR_F)
		return (ft_errmsg(data->lstargs));
	if (!ft_syntaxerr(data))
		return (ft_errmsg(data->lstargs));
	return (1);
}
