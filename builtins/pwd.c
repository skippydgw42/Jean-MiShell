/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:34:19 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/04/20 16:36:32 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

void	ft_pwd(t_env *lstenv)
{
	while (ft_strcmp(lstenv->varName, "PWD") != 0)
		lstenv = lstenv->next;
	printf("%s\n", lstenv->path);
}