/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:24:32 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/06/16 17:37:36 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

static int	ft_free_lstenv(t_data *data)
{
	t_env	*ptr;

	while (data->lstenv)
	{
		ptr = data->lstenv;
		if (ptr->varname)
			free(ptr->varname);
		if (ptr->value)
			free(ptr->value);
		data->lstenv = data->lstenv->next;
		free(ptr);
	}
	return (EXIT_SUCCESS);
}

int	ft_free_lstargs(t_data *data)
{
	t_args	*ptr;

	while (data->lstargs)
	{
		ptr = data->lstargs;
		if (ptr->str)
			free(ptr->str);
		data->lstargs = data->lstargs->next;
		free(ptr);
	}
	return (EXIT_SUCCESS);
}

int	ft_free_data(t_data *data)
{
	ft_free_lstenv(data);
	free(data);
	return (EXIT_SUCCESS);
}

int	ft_freenode(t_args *lstargs)
{
	if (lstargs->str)
		free(lstargs->str);
	if (lstargs)
		free(lstargs);
	return (EXIT_SUCCESS);
}
