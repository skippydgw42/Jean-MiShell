/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:31:08 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/02/23 16:09:53 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_recursive(unsigned int n, int fd)
{
	char	c;

	c = n % 10 + '0';
	if (n >= 10)
		ft_recursive(n / 10, fd);
	write (fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	if (n < 0)
	{
		write (fd, "-", 1);
		nb = n * -1;
	}
	else
		nb = n;
	ft_recursive(nb, fd);
}
