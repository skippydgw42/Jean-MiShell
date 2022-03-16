/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:21:15 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/02/23 16:00:17 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_length(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && ft_isnum(str[i]))
	{
		i++;
	}
	return (i);
}

static double	ft_atof_help(int loc_comma, int lenght, char *str)
{
	double	nb;
	double	rst;
	int		i;

	i = 0;
	str[loc_comma + 1 + lenght] = 0;
	nb = ft_atol(str);
	rst = ft_atol(&str[loc_comma + 1]);
	str[loc_comma] = 0;
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isnum(str[i]))
			rst = 0;
		i++;
	}
	while (lenght-- > 0)
		rst *= 0.1;
	if (nb < 0)
		rst *= -1;
	nb += rst;
	return (nb);
}

double	ft_atof(const char *str_src)
{
	char	*str;
	int		loc_comma;
	int		lenght;
	double	nb;

	loc_comma = 0;
	str = ft_strdup(str_src);
	while (str[loc_comma] != '.' && str[loc_comma])
		loc_comma++;
	lenght = ft_length(&str[loc_comma + 1]);
	if (lenght > 7)
		lenght = 7;
	nb = ft_atof_help(loc_comma, lenght, str);
	free(str);
	return (nb);
}
