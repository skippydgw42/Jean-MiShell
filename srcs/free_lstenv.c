/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lstenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 12:09:52 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/04/25 15:40:57 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

int	ft_free_lstenv(t_env *lstenv)
{
	t_env	*ptr;

	while (lstenv)
	{
		ptr = lstenv;
		if (ptr->varName)
			free(ptr->varName);
		if (ptr->value)
			free(ptr->value);
		lstenv = lstenv->next;
		free(ptr);
	}
	return (EXIT_SUCCESS);
}
