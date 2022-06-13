/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:49:10 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/06/13 10:49:45 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

void	ft_free_tstr(char ***src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		ft_free_dstr(src[i]);
		i++;
	}
	free(src);
}
