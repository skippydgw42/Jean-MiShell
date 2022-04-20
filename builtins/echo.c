/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:21:15 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/04/20 19:05:54 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

void	ft_echo(char *str, int flag)
{

// -nnnn -nnnnnnn -nnnn : affiche str
// -nnnn -nnnnnnn -nnnp : affiche -nnnp str
	if (str)
	{
		printf("%s", str);
		if (!flag)
			printf("\n");
	}
	else
		printf("\n");
}