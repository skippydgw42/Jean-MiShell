/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:47:36 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/06/16 12:12:30 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

static int	ft_nb_of_flag(t_args *start)
{
	int		i;
	t_args	*ptr;

	i = 0;
	ptr = start;
	if (ptr->flag == CMD_F || ptr->flag == BUILT_F)
	{
		ptr = ptr->next;
		i++;
	}
	if (!ptr)
		return (i);
	while (ptr)
	{
		if (ptr->flag == PIPE_F)
			break ;
		if (ptr->flag == STR_F)
			i++;
		ptr = ptr->next;
	}
	return (i);
}

static char	***ft_get_flags_cmd_help(t_args *start, char ***rtn, int i, int *j)
{
	if (start->flag == CMD_F)
		rtn[i] = ft_calloc(ft_nb_of_flag(start) + 1, sizeof(char *));
	if (start->flag == BUILT_F)
		rtn[i] = ft_calloc(ft_nb_of_flag(start), sizeof(char *));
	if (!rtn[i])
		return (NULL);
	if (start->flag == CMD_F)
	{
		rtn[i][*j] = ft_strdup(start->str);
		(*j)++;
	}
	start = start->next;
	while (start)
	{
		if (start->flag == PIPE_F)
			break ;
		if (start->flag == STR_F)
		{
			rtn[i][*j] = ft_strdup(start->str);
			(*j)++;
		}
		start = start->next;
	}
	return (&rtn[i]);
}

char	***ft_get_flags_cmd(t_data *data, int nb_cmd)
{
	int		i;
	int		j;
	t_args	*start;
	char	***rtn;

	i = 0;
	start = data->args_start;
	rtn = ft_calloc(nb_cmd + 1, sizeof(char **));
	if (!rtn)
		return (NULL);
	while (start)
	{
		j = 0;
		if (start->flag == CMD_F || start->flag == BUILT_F)
		{
			if (ft_get_flags_cmd_help(start, rtn, i, &j) == NULL)
				return (NULL);
		}
		if (!start)
			break ;
		if (start->flag == PIPE_F)
			i++;
		start = start->next;
	}
	return (rtn);
}
