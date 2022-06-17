/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:57:11 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/06/17 14:25:11 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

static char	*ft_cpyold_path(t_data *data)
{
	char	*ret;

	while (data->lstenv && ft_strcmp(data->lstenv->varname, "PWD") != 0)
		data->lstenv = data->lstenv->next;
	ret = ft_strdup(data->lstenv->value);
	data->lstenv = data->env_start;
	return (ret);
}

static int	ft_check_pwd(t_data *data, char *str)
{
	t_env	*ptr;

	ptr = data->env_start;
	if (ptr == NULL)
		return (0);
	while (ptr)
	{
		if (ft_strcmp(ptr->varname, str) == 0)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

static void	ft_setpwd(t_data *data, char *varname, int x)
{
	char	**str;
	char	*tmp;

	str = malloc(sizeof(char *) * 2);
	if (!str)
	{
		perror("Error");
		return ;
	}
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

static int	ft_check_dstr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_cd(char **str, t_data *data)
{
	if (!str)
		return ;
	if (!ft_check_dstr(str))
		return ;
	if (chdir(str[0]) == -1)
	{
		perror(str[0]);
		g_val_rtn = 1;
	}
	else
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
		g_val_rtn = 0;
	}
	data->lstenv = data->env_start;
}
