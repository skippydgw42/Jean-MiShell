/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   postpars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:22:36 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/06/16 17:46:45 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

static int	ft_paralcpy(t_data *data, char *str, char *dst, int q)
{
	int		i;
	int		j;
	int		roll;
	char	*g_var;

	i = 0;
	j = 0;
	roll = ft_rollst(&data->lstenv, str, q);
	if (roll == 1)
	{
		while (data->lstenv->value[j])
			dst[i++] = data->lstenv->value[j++];
	}
	else if (roll == 2)
	{
		g_var = ft_itoa(g_val_rtn);
		while (g_var[j])
			dst[i++] = g_var[j++];
		free(g_var);
	}
	data->lstenv = data->env_start;
	return (i);
}

static void	ft_rcpy(t_data *data, char *str, char *dst, int q)
{
	int	i;
	int	j;
	int	prev_q;

	i = 0;
	j = 0;
	while (str[i])
	{
		prev_q = q;
		q = ft_quotes(str[i], q);
		if (str[i] == '$' && q != 1)
		{
			j = j + ft_paralcpy(data, &str[i], &dst[j], q);
			i++;
			while (str[i] && !ft_separator(str[i]))
				i++;
		}
		else if ((prev_q == 0 && q == 2) || (prev_q == 2 && q == 0))
			i++;
		else if ((prev_q == 0 && q == 1) || (prev_q == 1 && q == 0))
			i++;
		else
			dst[j++] = str[i++];
	}
	dst[j] = '\0';
}

int	ft_separator(char c)
{
	if ((c >= 48 && c <= 57) || c == '_')
		return (0);
	else if ((c >= 65 && c <= 90) || c == '?')
		return (0);
	else if (c >= 97 && c <= 122)
		return (0);
	return (1);
}

int	ft_rollst(t_env **lst, char *str, int q)
{
	char	*to_find;

	if (q != 1)
	{
		to_find = ft_find_varname(str, q);
		if (!ft_strcmp(to_find, "?"))
		{
			free(to_find);
			return (2);
		}
		while (*lst)
		{
			if (!ft_strcmp(to_find, (*lst)->varname))
			{
				free(to_find);
				return (1);
			}
			*lst = (*lst)->next;
		}
		free(to_find);
	}
	return (0);
}

int	ft_replace(t_data *data, t_args *args)
{
	int		addlen;
	int		dellen;
	char	*dst;

	addlen = ft_findaddlen(data, args->str);
	dellen = ft_finddellen(args->str);
	dst = malloc(sizeof(char) * (ft_strlen(args->str) - dellen + addlen + 1));
	if (!dst)
		return (false);
	ft_rcpy(data, args->str, dst, 0);
	free(args->str);
	args->str = NULL;
	args->str = dst;
	return (true);
}
