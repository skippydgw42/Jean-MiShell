/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 12:04:12 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/05/30 13:47:41 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

int	ft_redirerr(t_data *data)
{
	int	ct;

	ct = 0;
	while (data->lstargs)
	{
		if (ct == 3)
			return (0);
		else if (ct > 0 && data->lstargs->flag != REDIR_F)
			ct = 0;
		if (data->lstargs->flag == REDIR_F)
		{
			if (!ft_strcmp(data->lstargs->str, ">>"))
				ct += 2;
			else
				ct++;
		}
		data->lstargs = data->lstargs->next;
	}
	data->lstargs = data->args_start;
	return (1);
}

int	ft_parserr(t_data *data)
{
	if (!ft_redirerr(data))
		return (0);
	if (data->lstargs->flag == PIPE_F)
		return (0);
	while (data->lstargs->next)
	{
		if (data->lstargs->flag == PIPE_F)
			if (data->lstargs->next->flag == PIPE_F)
				return (0);
		data->lstargs = data->lstargs->next;
	}
	if (data->lstargs->flag == PIPE_F || data->lstargs->flag == REDIR_F)
		return (0);
	return (1);
}