/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:35:42 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/05/16 11:36:39 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

int	ft_comp_redir(char *str)
{
	if (!strcmp(str, "|"))
		return (1);
	else if (!strcmp(str, "<") || !strcmp(str, ">"))
		return (1);
	else if (!strcmp(str, "<<") || !strcmp(str, ">>"))
		return (1);
	return (0);
}

int	ft_comp_built(char *str)
{
	return (0);
}

int	ft_analyse_str(char *str)
{
	int	i;
	int	q;

	i = 0;
	q = 0;
	if (ft_comp_redir(str))
		return (REDIR_F);
	// if (ft_comp_redir(str))
	// 	return (CMD_F);
	return (STR_F);
}

void	ft_flag(t_data *data)
{
	int	ret;

	while (data->lstargs)
	{
		ret = ft_analyse_str(data->lstargs->str);
		if (ret == 0)
			data->lstargs->flag = CMD_F;
		else if (ret == 1)
			data->lstargs->flag = REDIR_F;
		else if (ret == 2)
			data->lstargs->flag = STR_F;
		data->lstargs = data->lstargs->next;
	}
	data->lstargs = data->args_start;
}