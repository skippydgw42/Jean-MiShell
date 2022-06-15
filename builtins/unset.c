/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:58:28 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/06/15 11:00:21 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

static void	ft_unset_str(char *varname, t_data *data)
{
	t_env	*env;
	t_env	*previous;

	previous = NULL;
	env = data->lstenv;
	if (env == NULL)
		return ;
	while (env)
	{
		if (env->is_export == 1 && ft_strcmp(varname, env->varname) == 0)
		{
			if (previous)
				previous->next = env->next;
			else
			{
				data->env_start = env->next;
				data->lstenv = data->env_start;
			}
			free(env->varname);
			free(env->value);
			free(env);
		}
		previous = env;
		env = env->next;
	}
}

void	ft_unset(char **varnames, t_data *data)
{
	int	i;

	if (!varnames)
		return ;
	i = 0;
	while (varnames[i])
	{
		if (ft_check_varname(varnames[i]) == false)
		{
			printf("Jean_MiShell: unset: `%s': not a valid identifier\n",
				varnames[i]);
		}
		ft_unset_str(varnames[i], data);
		i++;
	}
	g_val_rtn = 0;
}
