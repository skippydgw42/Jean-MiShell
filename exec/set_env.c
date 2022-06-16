/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:16:09 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/06/16 11:16:38 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

static int	ft_size_lst_env(t_data *data)
{
	int		i;
	t_env	*start;

	i = 0;
	start = data->env_start;
	while (start)
	{
		i++;
		start = start->next;
	}
	return (i);
}

char	**ft_set_env(t_data *data)
{
	char	**rtn;
	char	*ptr;
	t_env	*start;
	int		i;

	rtn = ft_calloc(ft_size_lst_env(data) + 1, sizeof(char *));
	if (rtn == NULL)
		return (rtn);
	start = data->env_start;
	i = 0;
	while (start)
	{
		rtn[i] = ft_strjoin(start->varname, "=");
		ptr = rtn[i];
		rtn[i] = ft_strjoin(rtn[i], start->value);
		free(ptr);
		i++;
		start = start->next;
	}
	return (rtn);
}
