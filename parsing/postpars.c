/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   postpars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:22:36 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/05/11 16:15:52 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

int	ft_separator(char c)
{
	if ((c >= 48 && c <= 57) || c == '_')
		return (0);
	else if (c >= 65 && c <= 90)
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

int	ft_paralcpy(t_data *data, char *str, char *dst, int q)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_rollst(&data->lstenv, str, q))
	{
		while (data->lstenv->value[j])
			dst[i++] = data->lstenv->value[j++];
	}
	data->lstenv = data->start;
	return (i);
}

void	ft_rcpy(t_data *data, char *str, char *dst, int q)
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

void	ft_replace(t_data *data, t_args *args)
{
	int		addlen;
	int		dellen;
	char	*dst;

	addlen = ft_findaddlen(data, args->str);
	dellen = ft_finddellen(args->str);
	dst = malloc(sizeof(char) * (ft_strlen(args->str) - dellen + addlen + 1));
	ft_rcpy(data, args->str, dst, 0);
	free(args->str);
	args->str = NULL;
	args->str = ft_strdup(dst);
}
