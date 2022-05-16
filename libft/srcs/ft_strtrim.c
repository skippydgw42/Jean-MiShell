/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:01:23 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/02/23 16:10:37 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_charset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	end;
	unsigned int	i;
	unsigned int	size;
	char			*dst;

	if (!s1 || !set || s1[0] == 0)
		return (ft_calloc(1, 1));
	start = 0;
	end = ft_strlen(s1) - 1;
	i = -1;
	while (ft_is_charset(s1[start], set) && s1[start])
		start++;
	while (ft_is_charset(s1[end], set) && end > 0)
		end--;
	size = end - start + 1;
	if (start == ft_strlen(s1))
		size = 0;
	dst = ft_calloc(size + 1, sizeof(char));
	if (!dst)
		return (0);
	while (++i < size)
		dst[i] = s1[i + start];
	return (dst);
}
