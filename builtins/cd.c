/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:57:11 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/05/05 16:51:23 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

char	*ft_cpyold_path(t_env *lstenv)
{
	char	*ret;

	while (ft_strcmp(lstenv->varname, "PWD") != 0)
		lstenv = lstenv->next;
	ret = ft_strdup(lstenv->value);
	return (ret);
}

void	ft_cd(char *str, t_env *lstenv)
{
	if (chdir(str) == -1)
		perror(str);
	else
	{
		while (ft_strcmp(lstenv->varname, "OLDPWD") != 0)
			lstenv = lstenv->next;
		if (lstenv->value)
			free(lstenv->value);
		lstenv->value = ft_cpyold_path(lstenv);
		while (ft_strcmp(lstenv->varname, "PWD") != 0)
			lstenv = lstenv->next;
		if (lstenv->value)
			free(lstenv->value);
		lstenv->value = getcwd(NULL, 0);
	}
}
/*          cd nature         */
	// char	*path;

	// if (!str)
	// {
	// 	path = getenv("HOME");
	// 	chdir(path);
	// }
	