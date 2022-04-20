/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:57:11 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/04/20 16:29:04 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

char	*ft_cpyold_path(t_env *lstenv)
{
	char	*ret;

	while (ft_strcmp(lstenv->varName, "PWD") != 0)
		lstenv = lstenv->next;
	ret = ft_strdup(lstenv->path);
	return (ret);
}

void	ft_cd(char *str, t_env *lstenv)
{
	if (chdir(str) == -1)
		perror(str);
	else
	{
		while (ft_strcmp(lstenv->varName, "OLDPWD") != 0)
			lstenv = lstenv->next;
		if (lstenv->path)
			free(lstenv->path);
		lstenv->path = ft_cpyold_path(lstenv);
		while (ft_strcmp(lstenv->varName, "PWD") != 0)
			lstenv = lstenv->next;
		if (lstenv->path)
			free(lstenv->path);
		lstenv->path = getcwd(NULL, 0);
	}
}
/*          cd nature         */
	// char	*path;

	// if (!str)
	// {
	// 	path = getenv("HOME");
	// 	chdir(path);
	// }
	