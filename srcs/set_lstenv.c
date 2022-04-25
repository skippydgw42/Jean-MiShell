/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_lstenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:24:42 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/04/25 12:09:05 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

int ft_set_lstenv(char **env, t_env *lstenv)
{
	(void)lstenv;
	int i;
	char **split;

	i = 0;
	while (env[i])
	{
		split = ft_split(env[i], '=');
		lstenv->varName = split[0];
		lstenv->value = split[1];
		if (lstenv->value == NULL)
			lstenv->value = "";
		i++;
	}
	return (EXIT_SUCCESS);
}
