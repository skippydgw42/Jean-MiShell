/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:32:20 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/05/16 14:07:44 by mdegraeu         ###   ########.fr       */
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
		while (str[i] == ' ' && ft_quotes(str[i], q) == 0)
			i++;
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

	i = 0;
	j = 0;
	while (data->lstargs)
	{
		ft_replace(data, data->lstargs);
		data->lstargs = data->lstargs->next;
	}
	data->lstargs = data->args_start;
}

int	ft_parsing(t_data *data, char *str)
{
	data->lstargs = NULL;
	if (ft_is_close(str))
		return (0);
	ft_preparsing(&data->lstargs, str);
	data->args_start = data->lstargs;
	printf("\n=========prepars out=========\n");
	while (data->lstargs)
	{
		printf("str: %s\n",data->lstargs->str);
		data->lstargs = data->lstargs->next;
	}
	data->lstargs = data->args_start;
	ft_flag(data);
	ft_postpars(data);
	printf("\n=========postpars out=========\n");
	while (data->lstargs)
	{
		printf("str: %s\n",data->lstargs->str);
		data->lstargs = data->lstargs->next;
	}
	data->lstargs = data->args_start;
	return (1);
}