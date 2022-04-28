/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:35:15 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/04/28 13:55:52 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

static int	ft_size_lst(t_data *data)
{
	int	i;

	i = 0;
	data->lstenv = data->start;
	while (data->lstenv)
	{
		if (data->lstenv->is_export == true)
			i++;
		data->lstenv = data->lstenv->next;
	}
	data->lstenv = data->start;
	return (i);
}

static int	ft_print(t_data *data, char *str)
{
	data->lstenv = data->start;
	while (data->lstenv)
	{
		if (ft_strcmp(data->lstenv->varName, str) == 0)
		{
			if (data->lstenv->is_export == true)
				printf("declare -x %s=\"%s\"\n", data->lstenv->varName, data->lstenv->value);
			break;
		}
		data->lstenv = data->lstenv->next;
	}
	data->lstenv = data->start;
	return (EXIT_SUCCESS);
}

static int ft_print_export(t_data *data)
{
	char *buff;
	char *was_print;
	int size_lst;
	int nb_print;

	was_print = NULL;
	size_lst = ft_size_lst(data);
	nb_print = 0;
	while (nb_print < size_lst)
	{
		buff = NULL;
		while (data->lstenv)
		{
			if (ft_strcmp(buff, data->lstenv->varName) >= 0)
			{
				if (was_print == NULL || strcmp(was_print, data->lstenv->varName) < 0)
				{
					free(buff);
					buff = ft_strdup(data->lstenv->varName);
				}
			}
			data->lstenv = data->lstenv->next;
		}
		if (was_print == buff)
			break ;
		ft_print(data, buff);
		if (ft_strlen(was_print))
			free(was_print);
		was_print = ft_strdup(buff);
		free(buff);
		data->lstenv = data->start;
		nb_print++;
	}
	free(was_print);
	return (EXIT_SUCCESS);
}

static int	ft_already_export(char *str, t_data *data)
{
	int i;

	i = 0;
	data->lstenv = data->start;
	while (data->lstenv->next)
	{
		if (ft_strcmp(str, data->lstenv->varName) == 0)
		{

			puts("caciaaaaaaaaaaaaaddaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
			return (true);
		}
		data->lstenv = data->lstenv->next;
		i++;
	}
	return (false);
}

// Si export n'a pas d'argument, il faut passer str = NULL a la fonction
int ft_export(char *str, t_data *data)
{
	char **split;
	int i;
	char *ptr;
	t_env *new;

	i = 0;
	if (ft_strlen(str))
	{
		split = ft_split(str, '=');
		if (ft_already_export(split[1], data) == true)
		{
			if (ft_strlen(data->lstenv->value))
				free(data->lstenv->value);
			data->lstenv->value = ft_strdup(split[1]);
		}
		else
		{

			new = malloc(sizeof(t_env));
			if (!new)
			{
				perror("Error:");
				exit(errno);
			}
			new->varName = ft_strdup(split[0]);
			new->value = ft_strdup(split[1]);
			if (new->value == NULL)
				new->value = "";
			new->is_export = true;
			new->next = NULL;
			while (data->lstenv->next)
			{
				data->lstenv = data->lstenv->next;
			}
			data->lstenv->next = new;
		}
			ft_free_dstr(split);
			data->lstenv = data->start;
	}
	else
	{
		ft_print_export(data);
	}
	return (EXIT_SUCCESS);
}
