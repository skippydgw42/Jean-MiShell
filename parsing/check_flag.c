/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:35:42 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/05/20 17:57:36 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

int	ft_piperedir_flags(char *str)
{
	if (!ft_strcmp(str, "|"))
		return (PIPE_F);
	else if (!ft_strcmp(str, "<") || !strcmp(str, ">") || !ft_strcmp(str, ">>"))
		return (REDIR_F);
	else if (!ft_strcmp(str, "<<"))
		return (HD_F);
	return (STR_F);
}

int	ft_cmdbuilt_flags(char *str)
{
	if (!ft_strcmp(str, "echo"))
		return (BUILT_F);
	return (CMD_F);
}

t_args	*ft_genericflags(t_args *lstargs, t_args *set)
{
	int	redir;

	redir = 0;
	while (lstargs)
	{
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

void	ft_cmdfileflags(t_args *lstargs)
{
	t_args	*set;

	while (lstargs)
	{
		set = lstargs;
		while (lstargs->next && lstargs->flag != PIPE_F)
		{
			if (set->flag == CMD_F || set->flag == BUILT_F)
				lstargs = lstargs->next;
			else if (lstargs->flag == REDIR_F)
			{
				lstargs->next->flag = FILE_F;
				lstargs = set;
				while (lstargs)
				{
					if (lstargs->flag != REDIR_F && lstargs->flag != FILE_F)
					{
						lstargs->flag = CMD_F;
						set = lstargs;
						break ;
					}
					lstargs = lstargs->next;
				}
			}
			else
				lstargs = lstargs->next;
		}
		lstargs = lstargs->next;
	}
}

void	ft_flag(t_data *data)
{
	t_args	*set;

	while (data->lstargs)
	{
		set = data->lstargs;
		data->lstargs = ft_genericflags(data->lstargs, set);
	}
	data->lstargs = data->args_start;
	ft_cmdfileflags(data->lstargs);
	data->lstargs = data->args_start;
}
