/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:56:35 by ltrinchi          #+#    #+#             */
/*   Updated: 2021/11/15 09:54:13 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	size_t	size;	
	char	*dst;

	i = -1;
	j = 0;
	if (!s1 || !s2)
		return (0);
	size = ft_strlen(s1) + ft_strlen(s2);
	dst = malloc(sizeof(char) * size + 1);
	if (!dst)
		return (0);
	while (++i < ft_strlen(s1))
		dst[i] = s1[i];
	while (i < size)
	{
		dst[i] = s2[j];
		i++;
		j++;
	}
	dst[i] = 0;
	return (dst);
}