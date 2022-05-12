/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:32:20 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/05/10 14:18:56 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

void	ft_preparsing(t_args **lstargs, char *str)
{
	int	q;
	int	i;
	int	n;
	t_args	*new;
	t_args	*prev;

	q = 0;
	i = 0;
	n = ft_nargs(str, q);
	prev = NULL;
	while (n)
	{
		new = malloc(sizeof(t_args));
		new->next = 0;
		if (prev)
			prev->next = new;
		new->str = ft_subcpy(&str[i], q);
		i = ft_strlen(new->str) + i + 1;
		if (!*lstargs)
			*lstargs = new;
		prev = new;
		n--;
	}
}

void	ft_postpars(t_data *data)
{
	int		i;
	int		j;
	t_args	*start;

	i = 0;
	j = 0;
	start = data->lstargs;
	while (data->lstargs)
	{
		if (ft_needreplace(data->lstargs->str))
			ft_replace(data, data->lstargs);
		// else
			// ft_supquotes(data->lstargs);
		data->lstargs = data->lstargs->next;
	}
	data->lstargs = start;
}

int	ft_parsing(t_data *data, char *str)
{
	t_args	*start;

	data->lstargs = NULL;
	if (ft_is_close(str))
		return (0);
	ft_preparsing(&data->lstargs, str);
	ft_postpars(data);
	start = data->lstargs;
	while (data->lstargs)
	{
		printf("%s\n", data->lstargs->str);
		data->lstargs = data->lstargs->next;
	}
	data->lstargs = start;
	return (1);
}