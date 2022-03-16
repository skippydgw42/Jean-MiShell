/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 11:37:19 by ltrinchi          #+#    #+#             */
/*   Updated: 2021/11/13 15:22:21 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		size;
	char	*dst;

	if (!s)
		return (0);
	i = 0;
	size = ft_strlen(s);
	dst = ft_calloc (size + 1, sizeof(char));
	if (!dst)
		return (0);
	while (i < size)
	{
		dst[i] = (*f)(i, s[i]);
		i++;
	}
	return (dst);
}
