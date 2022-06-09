/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepars_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:29:25 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/05/31 11:55:41 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

int	ft_needsplit(char *str)
{
	int	i;
	int	ct;
	int	q;

	i = 0;
	ct = 0;
	q = 0;
	while (str[i])
	{
		q = ft_quotes(str[i], q);
		if (q == 0 && str[i] == ' ')
		{
			if (str[i] == ' ')
			{
				while (str[i] == ' ')
					i++;
			}
			else
				i++;
			if (str[i])
				ct++;
		}
		else
			i++;
	}
	return (ct);
}

int	ft_sublen(char *str)
{
	int	i;
	int	q;

	i = 0;
	q = 0;
	while (str[i])
	{
		q = ft_quotes(str[i], q);
		if (q == 0 && str[i] == ' ')
			return (i);
		i++;
	}
	return (i);
}

void	ft_subcpy(t_args *new, char *str)
{
	int	len;
	int	i;

	i = 0;
	len = ft_sublen(str);
	new->str = malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		new->str[i] = str[i];
		i++;
	}
	new->str[i] = '\0';
}

void	ft_replacestr(t_args *lstargs)
{
	int		i;
	int		len;
	char	*dst;

	i = 0;
	len = ft_sublen(lstargs->str);
	dst = malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		dst[i] = lstargs->str[i];
		i++;
	}
	dst[i] = '\0';
	free(lstargs->str);
	lstargs->str = dst;
}

void	ft_splitlst(t_args *lstargs, int n)
{
	int		i;
	int		q;
	t_args	*new;
	t_args	*buff;

	i = 0;
	q = 0;
	buff = lstargs;
	while (n)
	{
		new = malloc(sizeof(t_args));
		while (lstargs->str[i])
		{
			q = ft_quotes(lstargs->str[i], q);
			if (q == 0 && lstargs->str[i] == ' ')
			{
				while (lstargs->str[i] == ' ')
					i++;
				break ;
			}
			i++;
		}
		ft_subcpy(new, &lstargs->str[i]);
		new->next = buff->next;
		buff->next = new;
		buff = new;
		n--;
	}
	ft_replacestr(lstargs);
}

void	ft_delspace(t_args *lstargs)
{
	int		i;
	int		j;
	int		q;
	char	*dst;

	i = 0;
	q = 0;
	while (lstargs->str[i])
	{
		q = ft_quotes(lstargs->str[i], q);
		if (q == 0 && lstargs->str[i] == ' ')
			break ;
		i++;
	}
	dst = malloc(sizeof(char) * (i + 1));
	j = 0;
	while (j < i)
	{
		dst[j] = lstargs->str[j];
		j++;
	}
	dst[j] = '\0';
	free(lstargs->str);
	lstargs->str = dst;
}

void	ft_secondsplitlst(t_data *data)
{
	int	needsplit;

	while (data->lstargs)
	{
		needsplit = ft_needsplit(data->lstargs->str);
		if (needsplit)
			ft_splitlst(data->lstargs, needsplit);
		else
		{
			ft_delspace(data->lstargs);
			data->lstargs = data->lstargs->next;
		}
	}
	data->lstargs = data->args_start;
	while (data->lstargs)
	{
		data->lstargs->flag = ft_piperedir_flags(data->lstargs->str);
		data->lstargs = data->lstargs->next;
	}
	data->lstargs = data->args_start;
}
