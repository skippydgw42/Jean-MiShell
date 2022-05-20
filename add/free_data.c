/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:24:32 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/05/20 15:24:33 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

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

int	ft_free_lstenv(t_data *data)
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

int	ft_free_data(t_data *data)
{
	ft_free_lstargs(data);
	ft_free_lstenv(data);
	free(data);
}
