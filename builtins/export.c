/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:35:15 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/04/29 14:26 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

static int	ft_size_lst(t_data *data)
{
	int	i;

	i = 0;
	data->lstenv = data->env_start;
	while (data->lstenv)
	{
		if (data->lstenv->is_export == true)
			i++;
		data->lstenv = data->lstenv->next;
	}
	data->lstenv = data->env_start;
	return (i);
}

static void	ft_print(t_data *data, char *str)
{
	t_env	*env;

	env = data->env_start;
	while (env)
	{
		if (ft_strcmp(env->varname, str) == 0)
		{
			if (env->is_export == true)
			{
				if (env->value)
				{
					printf("declare -x %s=\"%s\"\n", env->varname, env->value);
				}
				else
					printf("declare -x %s\n", env->varname);
			}
			break ;
		}
		env = env->next;
	}
}

static void	ft_print_export(t_data *data)
{
	char	*buff;
	char	*was_print;
	int		size_lst;
	int		nb_print;

	was_print = NULL;
	size_lst = ft_size_lst(data);
	nb_print = 0;
	while (nb_print < size_lst)
	{
		buff = NULL;
		while (data->lstenv)
		{
			if (ft_strcmp(buff, data->lstenv->varname) >= 0)
			{
				if (was_print == NULL || strcmp(was_print,
						data->lstenv->varname) < 0)
				{
					free(buff);
					buff = ft_strdup(data->lstenv->varname);
				}
			}
			data->lstenv = data->lstenv->next;
		}
		ft_print(data, buff);
		free(was_print);
		was_print = ft_strdup(buff);
		free(buff);
		data->lstenv = data->env_start;
		nb_print++;
	}
	free(was_print);
}

static int	ft_already_export(char *varname, char *value, t_data *data)
{
	t_env	*env;

	env = data->env_start;
	while (env)
	{
		if (ft_strcmp(varname, env->varname) == 0)
		{
			if (value)
			{
				free(env->value);
				env->value = ft_strdup(value);
				free(value);
			}
			free(varname);
			return (true);
		}
		env = env->next;
	}
	return (false);
}

char	*ft_get_varname(char *str)
{
	char	*ptr;

	ptr = ft_strchr(str, '=');
	if (!ptr)
		return (ft_strdup(str));
	return (ft_substr(str, 0, ptr - str));
}

char	*ft_get_value(char *str)
{
	char	*ptr;

	ptr = ft_strchr(str, '=');
	if (!ptr)
		return (NULL);
	return (ft_substr(str, ptr - str + 1, ft_strlen(ptr)));
}

void	ft_add_back(char *varname, char *value, t_data *data)
{
	t_env	*env;
	t_env	*buff;
	t_env	*new;

	env = data->env_start;
	buff = NULL;
	while (env)
	{
		buff = env;
		env = env->next;
	}
	new = malloc(sizeof(t_env));
	if (!new)
	{
		perror("Error:");
		exit(0);
	}
	new->varname = ft_strdup(varname);
	free(varname);
	new->value = ft_strdup(value);
	free(value);
	new->next = NULL;
	new->is_export = true;
	buff->next = new;
}

int	ft_export_str(char *str, t_data *data)
{
	char	*varname;
	char	*value;

	varname = ft_get_varname(str);
	if (ft_check_varname(varname) == false)
	{
		printf("Jean_MiShell: export: `%s': not a valid identifier\n", varname);
	}
	value = ft_get_value(str);
	if (ft_already_export(varname, value, data) == true)
	{
		return (EXIT_SUCCESS);
	}
	ft_add_back(varname, value, data);
	return (EXIT_SUCCESS);
}

int	ft_export(char **str, t_data *data)
{
	int	i;

	i = 0;
	if (str[i])
	{
		while (str[i])
		{
			ft_export_str(str[i], data);
			// free(str[i]);
			i++;
		}
		// free(str);
	}
	else
		ft_print_export(data);
	return (EXIT_SUCCESS);
}

//NOTE Si export n'a pas d'argument, il faut passer str = NULL a la fonction
//NOTE export luca -> luca
//NOTE export luca="" -> luca=""
//NOTE	export luca (avec luca="qch" dans env) alors rien
//NOTE	export affichage d'erreur quand le noms des var commence par un numero
