/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:59:50 by mdegraeu          #+#    #+#             */
/*   Updated: 2021/11/05 11:10:55 by mdegraeu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dst_c;
	char	*src_c;

	i = 0;
	if (!dst && !src)
		return (NULL);
	dst_c = (char *)dst;
	src_c = (char *)src;
	if (src < dst)
	{
		while (i < n)
		{
			dst_c[n - i - 1] = src_c[n - i -1];
			i++;
		}
	}
	else
		ft_memcpy(dst, src, n);
	return (dst_c);
}
