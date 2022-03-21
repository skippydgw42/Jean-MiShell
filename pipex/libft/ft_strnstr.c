/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:33:52 by mdegraeu          #+#    #+#             */
/*   Updated: 2021/11/05 13:48:00 by mdegraeu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	x;

	i = 0;
	j = 0;
	if (ft_strlen(to_find) == 0)
		return ((char *)&str[i]);
	while (str[i] && i < len)
	{
		x = i;
		while (str[x] == to_find[j] && x < len)
		{
			if (to_find[j + 1] == '\0')
				return ((char *)&str[i]);
			x++;
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
