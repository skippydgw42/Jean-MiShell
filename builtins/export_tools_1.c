/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_tools_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:23:11 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/06/15 16:28:24 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

static int	ft_size_lst(t_data *data)
{
	int	i;

	i = 0;
	data->lstenv = data->env_start;
	while (data->lstenv)
	{
		if (data->lstenv->is_export == true)
			i++;
		data->lstenv = data->lstenv->next;
	}
	data->lstenv = data->env_start;
	return (i);
}

static void	ft_print(t_data *data, char *str)
{
	t_env	*env;

	env = data->env_start;
	while (env)
	{
		if (ft_strcmp(env->varname, str) == 0)
		{
			if (env->is_export == true)
			{
				if (env->value)
				{
					printf("declare -x %s=\"%s\"\n", env->varname, env->value);
				}
				else
					printf("declare -x %s\n", env->varname);
			}
			break ;
		}
		env = env->next;
	}
}

static char	*ft_print_export_help(t_data *data, char *buff, char *was_print)
{
	ft_print(data, buff);
	free(was_print);
	was_print = ft_strdup(buff);
	free(buff);
	return (was_print);
}

static char	*ft_buff(char *buff, t_data *data)
{
	free(buff);
	return (ft_strdup(data->lstenv->varname));
}

void	ft_print_export(t_data *data)
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
		if (data->lstenv == NULL)
			return ;
		while (data->lstenv)
		{
			if ((ft_strcmp(buff, data->lstenv->varname) >= 0)
				&& (was_print == NULL || ft_strcmp(was_print,
						data->lstenv->varname) < 0))
				buff = ft_buff(buff, data);
			data->lstenv = data->lstenv->next;
		}
		was_print = ft_print_export_help(data, buff, was_print);
		data->lstenv = data->env_start;
		nb_print++;
	}
}
