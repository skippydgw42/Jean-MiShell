/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:35:42 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/06/16 17:43:00 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

static t_args	*ft_setcmdflag(t_args *lstargs, t_args *set)
{
	while (lstargs && lstargs->flag != PIPE_F)
	{
		if (lstargs->flag == STR_F && set->flag != CMD_F
			&& set->flag != BUILT_F)
		{
			lstargs->flag = ft_cmdbuilt_flags(lstargs->str);
			set = lstargs;
		}
		lstargs = lstargs->next;
	}
	return (lstargs);
}

static void	ft_cmdfileflags(t_args *lstargs)
{
	t_args	*set;

	while (lstargs)
	{
		set = lstargs;
		while (lstargs && lstargs->flag != PIPE_F)
		{
			if (lstargs && lstargs->flag == REDIR_F)
			{
				if (lstargs->next && lstargs->next->flag == STR_F)
					lstargs->next->flag = FILE_F;
			}
			else if (lstargs && lstargs->flag == HD_F)
			{
				if (lstargs->next && lstargs->next->flag == STR_F)
					lstargs->next->flag = DELIM_F;
			}
			lstargs = lstargs->next;
		}
		lstargs = set;
		lstargs = ft_setcmdflag(lstargs, set);
		if (lstargs)
			lstargs = lstargs->next;
	}
}

t_args	*ft_genericflags(t_args *lstargs, t_args *set)
{
	int	redir;

	redir = 0;
	while (lstargs)
	{
		if (!ft_strcmp(lstargs->str, "|") && lstargs->next)
			lstargs = lstargs->next;
		lstargs->flag = ft_piperedir_flags(lstargs->str);
		if (lstargs->flag == REDIR_F || lstargs->flag == HD_F)
			redir = 1;
		else if (lstargs->flag == PIPE_F || !lstargs->next)
		{
			if (redir == 0)
				set->flag = ft_cmdbuilt_flags(set->str);
			return (lstargs->next);
		}
		lstargs = lstargs->next;
	}
	return (lstargs);
}

void	ft_flag(t_data *data)
{
	data->lstargs = data->args_start;
	ft_cmdfileflags(data->lstargs);
	data->lstargs = data->args_start;
}
