/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_heredocs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:50:58 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/06/16 11:51:08 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

static int	*ft_init_heredoc_help(t_args *start, int i, int *rtn)
{
	int	tmp;

	if (start->flag == HD_F)
	{
		start = start->next;
		tmp = rtn[i];
		rtn[i] = ft_heredoc(start->str);
		if (tmp != 0)
			close(tmp);
		if (rtn[i] < 0)
			return (NULL);
	}
	return (rtn);
}

int	*ft_init_heredoc(t_data *data, int nb_cmd)
{
	int		i;
	int		*rtn;
	t_args	*start;

	i = 0;
	rtn = ft_calloc(sizeof(int), nb_cmd);
	if (rtn == NULL)
		return (NULL);
	start = data->args_start;
	while (start)
	{
		if (ft_init_heredoc_help(start, i, rtn) == NULL)
			return (NULL);
		if (start == NULL)
			break ;
		if (start->flag == PIPE_F)
			i++;
		start = start->next;
	}
	return (rtn);
}
