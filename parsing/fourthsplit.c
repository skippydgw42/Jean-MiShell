/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fourthsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:57:36 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/06/16 17:43:49 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

static int	ft_checkvar(char *str)
{
	size_t	i;
	int		q;

	i = 0;
	q = 0;
	while (str[i])
	{
		q = ft_quotes(str[i], q);
		if (q == 0 && str[i] == '$' && i < ft_strlen(str))
			return (1);
		i++;
	}
	return (0);
}

void	ft_needsplitvar(t_args *lstargs)
{
	int		built;
	t_args	*ptr;

	built = 0;
	ptr = lstargs;
	while (ptr)
	{
		if (ptr->flag == BUILT_F)
			built = 1;
		if (ft_checkvar(ptr->str) && built == 0)
			ptr->flag = VARSPLIT_F;
		if (ptr->flag == PIPE_F)
			built = 0;
		ptr = ptr->next;
	}
}

void	ft_fourthsplitlst(t_data *data)
{
	int	n;

	n = 0;
	while (data->lstargs)
	{
		if (data->lstargs->flag == PIPE_F && ft_strcmp(data->lstargs->str, "|"))
			data->lstargs->flag = STR_F;
		if (data->lstargs->flag == VARSPLIT_F)
		{
			n = ft_needsplit(data->lstargs->str);
			if (n)
				ft_splitlst(data->lstargs, n);
			data->lstargs->flag = STR_F;
		}
		data->lstargs = data->lstargs->next;
	}
	data->lstargs = data->args_start;
}
