/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:32:23 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/03/16 13:52:11 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	err(void)
{
	write(2, "Error\n", 6);
	return (0);
}

int	err_split(char **str)
{
	free_doubleptr(str);
	write(2, "Malloc Error\n", 13);
	return (0);
}

int	err_mess(char *str, char **dstr)
{
	if (dstr)
		free_doubleptr(dstr);
	ft_putstr_fd(str, 2);
	return (0);
}

int	err_a(char *str, t_struct *vars)
{
	free_struct(vars);
	ft_putstr_fd(str, 2);
	return (0);
}

int	p_error(char *str)
{
	perror(str);
	return (0);
}
