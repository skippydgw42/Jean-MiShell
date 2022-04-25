/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:48:40 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/04/25 10:53:08 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_word(const char *haystack,
	const char *ndle, size_t n, size_t len)
{
	int	i;

	i = 0;
	while (ndle[i] && n < len)
	{
		if (haystack[i] != ndle[i])
			return (0);
		i++;
		n++;
	}
	if (!ndle[i])
		return (1);
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (needle[0] == 0)
		return ((char *)haystack);
	if (len == 0)
		return (0);
	while (haystack[i] && i < len - ft_strlen(needle) + 1)
	{
		if (haystack[i] == needle[0])
		{
			if (ft_check_word(&haystack[i], needle, i, len))
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (0);
}
