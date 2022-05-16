/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:00:24 by ltrinchi          #+#    #+#             */
/*   Updated: 2021/11/15 09:38:54 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "stdlib.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		*(char *)dst = *(char *)src;
		dst++;
		src++;
		i++;
	}
	dst -= n;
	return (dst);
}
