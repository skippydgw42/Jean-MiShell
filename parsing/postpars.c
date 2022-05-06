/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   postpars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:22:36 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/05/06 15:57:25 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

int	ft_needreplace(char *str)
{
	int	i;
	int	q;

	i = 0;
	q = 0;
	while (str[i])
	{
		q = ft_quotes(&str[i], q);
		if ((q == 2 || q == 0) && str[i] == '$')
			if (str[i + 1])
				return (1);
		i++;
	}
	return (0);
}

char	*ft_find_varName(char *str)
{
	int		i;
	int		j;
	int		cp;
	char	*var;

	i = 0;
	cp = 0;
	while (str[i] && (cp == 0 && str[i] != ' '))
	{
		if (str[i] == '$')
			cp = i;
		i++;
	}
	var = malloc(sizeof(char) * (i - cp));
	j = 0;
	while (cp < i)
	{
		var[j] = str[cp];
		j++;
		cp++;
	}
	var[j] = '\0';
	return (var);
}

int	ft_rollst(t_env *lst, char *str)
{
	char	*to_find;

	to_find = ft_find_varName(str);
	while (lst)
	{
		if (!ft_strcmp(to_find, lst->varname))
		{
			free(to_find);
			return (ft_strlen(lst->value));
		}
		lst = lst->next;
	}
	return (0);
}

char	*ft_replace(t_data *data, char *str)
{
	int		i;
	int		val;
	int		name;
	char	*dst;

	val = ft_rollst(data->lstenv, str);
	if (val)
		name = ft_strlen(data->lstenv->varname);
	else
		name = 0;
	dst = malloc(sizeof(char) * (ft_strlen(str) - name + val));
	
}

t_args	*ft_postpars(t_data *data, char **str)
{
	int		i;
	int		j;
	t_args	*args;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (ft_needreplace(str[i]))
		{
			ft_rollst(data->lstenv, str[i]);
			args->str = ft_replace(data->lstenv, str[i]);
		}
		else
			args->str = ft_strdup(str[i]);
		free(str[i]);
		i++;
	}
	return (args);
}