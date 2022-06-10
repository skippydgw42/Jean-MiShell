/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:57:11 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/06/09 09:13:55 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

char	*ft_cpyold_path(t_data *data)
{
	char	*ret;

	//free(OLDPWD) ?
	while (data->lstenv && ft_strcmp(data->lstenv->varname, "PWD") != 0)
		data->lstenv = data->lstenv->next;
	ret = ft_strdup(data->lstenv->value);
	data->lstenv = data->env_start;
	return (ret);
}

int	ft_check_pwd(t_data *data, char *str)
{
	while (data->lstenv)
	{
		if (ft_strcmp(data->lstenv->varname, str) == 0)
		{	
			data->lstenv = data->env_start;
			return (1);
		}
		data->lstenv = data->lstenv->next;
	}
	data->lstenv = data->env_start;
	return (0);
}

void	ft_setpwd(t_data *data, char *varname, int x)
{
	char	**str;
	char	*tmp;

	str = malloc(sizeof(char *) * 2);
	str[0] = ft_strjoin(varname, "=");
	tmp = str[0];
	if (x == 0)
		str[1] = ft_cpyold_path(data);
	else
		str[1] = getcwd(NULL, 0);
	str[0] = ft_strjoin(str[0], str[1]);
	free(str[1]);
	free(tmp);
	str[1] = 0;
	ft_export(str, data);
}

void	ft_cd(char *str, t_data *data)
{
	char	*oldpwd;

	if (!str)
		return ;
	if (chdir(str) == -1)
		perror(str);
	else //if (data->lstenv)
	{
		if (ft_check_pwd(data, "PWD"))
		{
			ft_setpwd(data, "OLDPWD", 0);
			while (ft_strcmp(data->lstenv->varname, "PWD") != 0)
				data->lstenv = data->lstenv->next;
			if (data->lstenv->value)
				free(data->lstenv->value);
			data->lstenv->value = getcwd(NULL, 0);
		}
		else
			ft_setpwd(data, "PWD", 1);
	}
	data->lstenv = data->env_start;
}
