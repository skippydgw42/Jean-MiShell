/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_lstenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:24:42 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/06/20 11:18:04 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

static t_env	*ft_set_lstenv_help(char **env, int i)
{
	char	**split;
	t_env	*new;

	split = ft_split(env[i], '=');
	new = malloc(sizeof(t_env));
	if (!new)
	{
		perror("Error set_lstenv");
		exit(EXIT_FAILURE);
	}
	new->varname = ft_strdup(split[0]);
	new->value = ft_strdup(split[1]);
	new->is_export = true;
	ft_free_dstr(split);
	return (new);
}

t_env	*ft_set_lstenv(char **env)
{
	int		i;
	t_env	*new;
	t_env	*start;
	t_env	*buff;

	i = 0;
	buff = NULL;
	start = NULL;
	while (env[i])
	{
		new = ft_set_lstenv_help(env, i);
		new->next = NULL;
		if (buff == NULL)
			start = new;
		else
			buff->next = new;
		buff = new;
		i++;
	}
	return (start);
}
