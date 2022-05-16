/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:38:50 by ltrinchi          #+#    #+#             */
/*   Updated: 2021/11/15 09:37:09 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "stdlib.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*(unsigned char *)b = c;
		b++;
		i++;
	}
	b -= len;
	return (b);
}
