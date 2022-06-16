/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 13:49:50 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/06/16 17:35:11 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

int	ft_errmsg(t_args *lstargs)
{
	printf("Parse error near `%s'\n", lstargs->str);
	return (0);
}

int	ft_errquotes(void)
{
	printf("Quotes error '\n");
	return (0);
}

int	ft_errdstr(char *str, char **cflags)
{
	printf("%s\n", str);
	ft_free_dstr(cflags);
	return (0);
}
