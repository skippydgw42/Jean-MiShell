/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_tools_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:23:22 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/06/16 17:38:47 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

int	ft_already_export(char *varname, char *value, t_data *data)
{
	t_env	*env;

	env = data->env_start;
	if (env == NULL)
		return (false);
	while (env)
	{
		if (ft_strcmp(varname, env->varname) == 0)
		{
			if (value)
			{
				free(env->value);
				env->value = ft_strdup(value);
				free(value);
			}
			free(varname);
			return (true);
		}
		env = env->next;
	}
	return (false);
}

char	*ft_get_varname(char *str)
{
	char	*ptr;

	ptr = ft_strchr(str, '=');
	if (!ptr)
		return (ft_strdup(str));
	return (ft_substr(str, 0, ptr - str));
}

char	*ft_get_value(char *str)
{
	char	*ptr;

	ptr = ft_strchr(str, '=');
	if (!ptr)
		return (NULL);
	return (ft_substr(str, ptr - str + 1, ft_strlen(ptr)));
}

static void	ft_add_back_help(t_env *buff, t_env *new, t_data *data)
{
	if (buff != NULL)
		buff->next = new;
	else
	{
		data->env_start = new;
		data->lstenv = new;
	}
}

void	ft_add_back(char *varname, char *value, t_data *data)
{
	t_env	*env;
	t_env	*buff;
	t_env	*new;

	env = data->env_start;
	buff = NULL;
	while (env)
	{
		buff = env;
		env = env->next;
	}
	new = malloc(sizeof(t_env));
	if (!new)
		perror("Error:");
	new->varname = ft_strdup(varname);
	free(varname);
	new->value = ft_strdup(value);
	free(value);
	new->next = NULL;
	new->is_export = true;
	ft_add_back_help(buff, new, data);
}
