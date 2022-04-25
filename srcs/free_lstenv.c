/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lstenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 12:09:52 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/04/25 12:17:54 by mdegraeu         ###   ########.fr       */
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
