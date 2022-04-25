/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_lstenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:24:42 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/04/25 15:41:29 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

t_env *ft_set_lstenv(char **env)
{
	char	**split;
	int		i;
	t_env	*new;
	t_env	*start;
	t_env	*buff;

	i = 0;
	buff = NULL;
	while (env[i])
	{
		split = ft_split(env[i], '=');
		new = malloc(sizeof(t_env));
		new->varName = split[0];
		new->value = split[1];
		new->next = NULL;
		if (buff == NULL)
		{
			start = new;
		}
		else
		{
			buff->next = new;
		}
		buff = new;
		i++;
	}
	return (start);
}
