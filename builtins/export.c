/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:27:31 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/04/27 16:29:16 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

static int	ft_size_lst(t_data *data)
{
	int	i;

	i = 0;
	while (data->lstenv->next)
	{
		if (data->lstenv->is_export == true)
			i++;
		data->lstenv = data->lstenv->next;
	}
	data->lstenv = data->start;
	return (i);
}

static int ft_print_export(t_data *data)
{
	char	*buff;
	char	*was_print;
	int		size_lst;
	int		nb_print;

	was_print = NULL;
	size_lst = ft_size_lst(data);
	nb_print = 0;
	while (nb_print < size_lst)
	{
		buff = NULL;
		while (data->lstenv->next)
		{
			if (ft_strcmp(buff, data->lstenv->varName) >= 0)
			{
				if (was_print == NULL)
				{
					buff = ft_strdup(data->lstenv->varName);
				}
				else if (strcmp(was_print, data->lstenv->varName) < 0)
				{
					buff = ft_strdup(data->lstenv->varName);
				}
			}
			data->lstenv = data->lstenv->next;
		}
		nb_print++;
		printf("%s\n", buff);
		was_print = ft_strdup(buff);
		data->lstenv = data->start;
	}
	return (EXIT_SUCCESS);
}

// Si export n'a pas d'argument, il faut passer str = NULL a la fonction
int ft_export(char *str, t_data *data)
{
	char **split;
	t_env *new;
	
	if (ft_strlen(str))
	{
		split = ft_split(str, '=');
		while (data->lstenv->next)
		{
			data->lstenv = data->lstenv->next;
		}
		new = malloc(sizeof(t_data));
		if (!new)
		{
			perror("Error:");
			exit(errno);
		}
		new->varName = ft_strdup(split[0]);
		new->value = ft_strdup(split[1]);
		ft_free_dstr(split);
		if (new->value == NULL)
			new->value = "";
		new->is_export = false;
		new->next = NULL;
		data->lstenv->next = new;
		data->lstenv = data->start;
	}
	else
	{
		ft_print_export(data);
	}
	return (EXIT_SUCCESS);
}
