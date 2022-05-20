/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:32:20 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/05/20 13:28:43 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

void	ft_presplitpipe(t_args **lstargs, char *str)
{
	int	q;
	int	i;
	int	n;
	t_args	*new;
	t_args	*prev;

	q = 0;
	i = 0;
	n = ft_npipe(str);
	prev = NULL;
	printf("npipe: %d\n", n);
	while (n)
	{
		while (str[i] == ' ' && ft_quotes(str[i], q) == 0)
			i++;
		new = malloc(sizeof(t_args));
		new->next = 0;
		if (prev)
			prev->next = new;
		new->str = ft_cpytopipe(&str[i], q);
		i = ft_strlen(new->str) + i;
		if (!*lstargs)
			*lstargs = new;
		prev = new;
		n--;
	}
}

void	ft_postpars(t_data *data)
{
	int	i;
	int	j;

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
	printf("\n=========presplit out=========\n");
	ft_presplitpipe(&data->lstargs, str);
	data->args_start = data->lstargs;
	while (data->lstargs)
	{
		printf("str: %s\n",data->lstargs->str);
		data->lstargs = data->lstargs->next;
	}
	data->lstargs = data->args_start;
	printf("\n=========prepars out=========\n");
	ft_secondsplitlst(data->lstargs);
	data->lstargs = data->args_start;
	while (data->lstargs)
	{
		printf("\nstr: %s\n",data->lstargs->str);
		data->lstargs = data->lstargs->next;
	}
	data->lstargs = data->args_start;
	printf("\n=============flag=============\n");
	ft_flag(data);
	printf("\n=========postpars out=========\n");
	ft_postpars(data);
	while (data->lstargs)
	{
		printf("str: %s      flag: %d\n",data->lstargs->str, data->lstargs->flag);
		data->lstargs = data->lstargs->next;
	}
	data->lstargs = data->args_start;
	return (1);
}

// void	ft_preparsing(t_args **lstargs, char *str)
// {
// 	int		q;
// 	int		i;
// 	int		n;
// 	t_args	*new;
// 	t_args	*prev;

// 	q = 0;
// 	i = 0;
// 	n = ft_nargs(str);
// 	prev = NULL;
// 	while (n)
// 	{
// 		while (str[i] == ' ' && ft_quotes(str[i], q) == 0)
// 			i++;
// 		new = malloc(sizeof(t_args));
// 		new->next = 0;
// 		if (prev)
// 			prev->next = new;
// 		new->str = ft_subcpy(&str[i], q);
// 		i = ft_strlen(new->str) + i;
// 		if (!*lstargs)
// 			*lstargs = new;
// 		prev = new;
// 		n--;
// 	}
// }