/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:01:09 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/02/23 16:07:38 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_position_char(char *base, int nb)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (nb == i)
			return (base[i]);
		i++;
	}
	return (0);
}

static int	recursive(long int nbr, char *tab, long int nbr_brut)
{
	int		i;
	char	*base;

	base = "0123456789";
	if (nbr < 0)
		nbr *= -1;
	if (nbr == 0)
	{
		tab[0] = base[0];
		tab[1] = 0;
	}
	if (nbr >= 10)
	{
		i = recursive(nbr / 10, tab, nbr_brut);
	}
	else if (nbr_brut < 0)
	{
		i = 1;
		tab[0] = '-';
	}
	else
		i = 0;
	tab[i] = ft_position_char(base, (nbr % 10));
	return (i + 1);
}

char	*ft_itoa(int nbr)
{
	int			size_base;
	long int	buff_nb;
	int			compteur;
	char		*nombre;

	buff_nb = nbr;
	compteur = 1;
	if (buff_nb < 0)
	{
		buff_nb *= -1;
		compteur++;
	}
	size_base = 10;
	while (buff_nb >= size_base)
	{
		buff_nb = buff_nb / size_base;
		compteur++;
	}
	nombre = ft_calloc(compteur + 1, sizeof(char));
	if (!nombre)
		return (0);
	buff_nb = nbr;
	recursive(buff_nb, nombre, nbr);
	return (nombre);
}
