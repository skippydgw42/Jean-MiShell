/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_varName.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:28:00 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/05/05 16:46:36 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

int	ft_check_varname(char *varname)
{
	int	i;

	i = 0;
	if (!ft_isalpha(varname[0]) && varname[0] != '_')
	{
		return (false);
	}
	while (varname[i])
	{
		if (!ft_isalnum(varname[i]) && varname[i] != '_')
		{
			return (false);
		}
		i++;
	}
	return (true);
}
