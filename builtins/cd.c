/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:57:11 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/06/15 09:33:33 by ltrinchi         ###   ########lyon.fr   */
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


int	ft_check_dstr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i >= 3)
	{
		printf("cd : too many arguments\n");
		return (0);
	}
	else if (i == 2)
	{
		printf("string not in pwd\n");
		return (0);
	}
	return (1);
}

void	ft_cd(char **str, t_data *data)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	if (!ft_check_dstr(str))
		return ;
	if (chdir(str[0]) == -1)
		perror(str[0]);
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
		 {
			ft_setpwd(data, "PWD", 1);
		 }
	}
	data->lstenv = data->env_start;
}

// void	ft_cd(char *str, t_data *data)
// {
// 	if (!str)
// 		return ;
// 	if (chdir(str) == -1)
// 		perror(str);
// 	else //if (data->lstenv)
// 	{
// 		if (ft_check_pwd(data, "PWD"))
// 		{
// 			ft_setpwd(data, "OLDPWD", 0);
// 			while (ft_strcmp(data->lstenv->varname, "PWD") != 0)
// 				data->lstenv = data->lstenv->next;
// 			if (data->lstenv->value)
// 				free(data->lstenv->value);
// 			data->lstenv->value = getcwd(NULL, 0);
// 		}
// 		else
// 			ft_setpwd(data, "PWD", 1);
// 	}
// 	data->lstenv = data->env_start;
// }