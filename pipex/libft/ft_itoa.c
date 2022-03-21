/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:12:30 by mdegraeu          #+#    #+#             */
/*   Updated: 2021/11/04 15:14:38 by mdegraeu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nb_div(long n)
{
	size_t	ct;

	ct = 1;
	if (n < 0)
	{
		n *= -1;
		ct++;
	}
	while (n > 9)
	{
		n = n / 10;
		ct++;
	}
	return (ct);
}

char	*ft_itoa(int n)
{
	size_t	i;
	long	nb;
	char	*num;

	nb = n;
	i = ft_nb_div(nb);
	num = malloc(sizeof(*num) * (i + 1));
	if (!num)
		return (NULL);
	num[i] = '\0';
	i--;
	if (nb < 0)
	{
		nb *= -1;
		num[0] = '-';
	}
	if (nb == 0)
		num[0] = '0';
	while (nb > 0)
	{
		num[i] = nb % 10 + '0';
		nb /= 10;
		i--;
	}
	return (num);
}
