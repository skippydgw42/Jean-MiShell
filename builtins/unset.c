/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:58:28 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/04/28 16:15:26 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

void	ft_unset(char *str, t_data *data)
{
	t_env	*env;
	t_env	*previous;

	if (!str)
		return ;
	previous = NULL;
	env = data->lstenv;
	while (env)
	{
		if (env->is_export == 1 && ft_strcmp(str, env->varName) == 0)
		{
			if (previous)
				previous->next = env->next;
			else
			{
				data->start = env->next;
				data->lstenv = data->start;
			}
			free(env->varName);
			free(env->value);
			free(env);
		}
		previous = env;
		env = env->next;
	}
}
