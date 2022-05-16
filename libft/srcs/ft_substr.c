/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:15:26 by ltrinchi          #+#    #+#             */
/*   Updated: 2021/11/15 09:53:34 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dst;

	if (!s)
		return (0);
	i = 0;
	if (start > ft_strlen(s))
		len = ft_strlen(s);
	if ((ft_strlen(s) - start) <= len)
		len = ft_strlen(s) - start;
	dst = malloc (sizeof(char) * len + 1);
	if (!dst)
		return (0);
	if (!s)
		return (0);
	while (i < len && start < ft_strlen(s))
	{
		dst[i] = s[start];
		i++;
		start++;
	}
	dst[i] = 0;
	return (dst);
}
