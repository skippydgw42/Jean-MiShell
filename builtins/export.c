/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:35:15 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/04/29 14:26 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

static int	ft_export_str(char *str, t_data *data)
{
	char	*varname;
	char	*value;

	varname = ft_get_varname(str);
	if (ft_check_varname(varname) == false)
	{
		printf("Jean_MiShell: export: `%s': not a valid identifier\n", varname);
		g_val_rtn = 1;
		return (EXIT_FAILURE);
	}
	value = ft_get_value(str);
	if (ft_already_export(varname, value, data) == true)
	{
		return (EXIT_SUCCESS);
	}
	ft_add_back(varname, value, data);
	g_val_rtn = 0;
	return (EXIT_SUCCESS);
}

int	ft_export(char **str, t_data *data)
{
	int	i;

	i = 0;
	if (str[i])
	{
		while (str[i])
		{
			ft_export_str(str[i], data);
			i++;
		}
	}
	else
		ft_print_export(data);
	return (EXIT_SUCCESS);
}
