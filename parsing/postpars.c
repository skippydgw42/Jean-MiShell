/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   postpars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:22:36 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/05/09 18:42:09 by mdegraeu         ###   ########.fr       */
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
			return (1);
		}
		lst = lst->next;
	}
	return (0);
}

void	ft_rcpy(t_data *data, char *str, char *dst)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			if (ft_rollst(data->lstenv, str))
			{
				while (data->lstenv->value[j])
					dst[k++] = data->lstenv->value[j++];
			}
			while (str[i] && str[i] != ' ')
				i++;
			data->lstenv = data->start;
		}
		else
			dst[k++] = str[i++];
	}
	dst[k] = '\0';
}

int	ft_finddellen(char *str)
{
	int	i;
	int	del;

	i = 0;
	del = 0;
	while (str[i])
	{
		if (str[i] == '$')
			while (str[i] && str[i] != ' ')
			{
				del++;
				i++;
			}
		else
			i++;
	}
	return (del);
}

int	ft_findaddlen(t_data *data, char *str)
{
	int	i;
	int	add;

	i = 0;
	add = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			ft_rollst(data->lstenv, str);
			add = add + ft_strlen(data->lstenv->value);
			data->lstenv = data->start;
		}
		i++;
	}
	data->lstenv = data->start;
	return (add);
}

void	ft_replace(t_data *data, t_args *args)
{
	int		addlen;
	int		dellen;
	char	*dst;

	addlen = ft_findaddlen(data, args->str);
	dellen = ft_finddellen(args->str);
	dst = malloc(sizeof(char) * (ft_strlen(args->str) - dellen + addlen));
	ft_rcpy(data, args->str, dst);
	free(args->str);
	args->str = dst;
}
