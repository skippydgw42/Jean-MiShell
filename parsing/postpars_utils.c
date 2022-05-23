/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   postpars_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:54:28 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/05/20 17:59:50 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

int	ft_needreplace(char *str)
{
	//fonction inutilisée ??
	int	i;
	int	q;

	i = 0;
	q = 0;
	while (str[i])
	{
		q = ft_quotes(str[i], q);
		if ((q == 2 || q == 0) && str[i] == '$')
			if (str[i + 1])
				return (1);
		i++;
	}
	return (0);
}

char	*ft_find_varname(char *str, int q)
{
	int		i;
	int		j;
	int		cp;
	char	*var;

	i = 0;
	cp = 0;
	while (str[i])
	{
		if (cp != 0 && ft_separator(str[i]))
		{
			q = 0;
			break ;
		}
		else if (str[i] == '$')
			cp = i + 1;
		i++;
	}
	var = malloc(sizeof(char) * (i - cp));
	if (q == 2)
		i--;
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

int	ft_finddellen(char *str)
{
	int	i;
	int	q;
	int	del;
	char	*temp;

	i = 0;
	q = 0;
	del = 0;
	while (str[i])
	{
		if (ft_quotes(str[i], q) != q)
		{
			q = ft_quotes(str[i], q);
			del++;
		}
		if (str[i] == '$' && q != 1)
		{
			temp = ft_find_varname(&str[i], q);
			del += ft_strlen(temp) + 1;
			free(temp);
			i++;
			while (str[i] && !ft_separator(str[i]))
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
	int	q;
	int	add;

	i = 0;
	q = 0;
	add = 0;
	while (str[i])
	{
		q = ft_quotes(str[i], q);
		if (str[i] == '$')
		{
			if (ft_rollst(&data->lstenv, &str[i], q))
				add = add + ft_strlen(data->lstenv->value);
			data->lstenv = data->env_start;
		}
		i++;
	}
	data->lstenv = data->env_start;
	return (add);
}
