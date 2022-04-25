/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_lstenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:24:42 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/04/25 16:41:58 by mdegraeu         ###   ########.fr       */
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
		new->varName = ft_strdup(split[0]);
		new->value = ft_strdup(split[1]);
		ft_free_dstr(split);
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
