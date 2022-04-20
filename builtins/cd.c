/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:57:11 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/04/20 14:43:31 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

void	ft_cd(char *str, t_data *data)
{
	// char	*path;

	// if (!str)
	// {
	// 	path = getenv("HOME");
	// 	chdir(path);
	// }
	if (chdir(str) == -1)
		perror(str);
	else
	{
		if (data->oldpwd)
			free(data->oldpwd);
		if (data->pwd)
		{
			data->oldpwd = ft_strdup(data->pwd);
			free(data->pwd);
		}
		data->pwd = getcwd(NULL, 0);
	}
	printf("old: %s\nnew: %s\n", data->oldpwd, data->pwd);
}