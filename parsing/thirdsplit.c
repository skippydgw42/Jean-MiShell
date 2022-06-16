/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thirdsplit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:15:40 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/06/16 17:50:35 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

static int	ft_majlstargs(t_args *lstargs)
{
	int		i;
	int		cpy;
	char	*dst;

	i = 0;
	cpy = 0;
	if (lstargs->str[i] == '>' || lstargs->str[i] == '<')
		while (lstargs->str[i] == '>' || lstargs->str[i] == '<')
			i++;
	else
		while (lstargs->str[i] != '>' && lstargs->str[i] != '<')
			i++;
	dst = malloc(sizeof(char) * (i + 1));
	if (!dst)
		return (false);
	while (cpy < i)
	{
		dst[cpy] = lstargs->str[cpy];
		cpy++;
	}
	dst[cpy] = '\0';
	free(lstargs->str);
	lstargs->str = dst;
	return (true);
}

static int	ft_splitbyredir(t_args *lstargs, int n)
{
	int		i;
	t_args	*new;
	t_args	*buff;

	i = 0;
	buff = lstargs;
	if (lstargs->str[i] == '>' || lstargs->str[i] == '<')
		while (lstargs->str[i] == '>' || lstargs->str[i] == '<')
			i++;
	else
		while (lstargs->str[i] != '>' && lstargs->str[i] != '<')
			i++;
	while (n && lstargs->str[i])
	{
		new = malloc(sizeof(t_args));
		if (!new)
			return (false);
		i = i + ft_setnew(new, &lstargs->str[i]);
		new->next = buff->next;
		buff->next = new;
		buff = new;
		n--;
	}
	ft_majlstargs(lstargs);
	return (true);
}

static int	ft_needrsplit(t_args *lstargs)
{
	int	i;
	int	q;

	i = 0;
	q = 0;
	while (lstargs->str[i])
	{
		q = ft_quotes(lstargs->str[i], q);
		while (q == 0 && (lstargs->str[i] == '>' || lstargs->str[i] == '<'))
			i++;
		if (!lstargs->str[i])
			return (0);
		else
			return (1);
		while (lstargs->str[i] && lstargs->str[i] != '>'
			&& lstargs->str[i] != '<')
			i++;
		if (lstargs->str[i])
			return (1);
		else
			return (0);
	}
	return (0);
}

void	ft_thirdsplitlst(t_data *data)
{
	int	n;

	while (data->lstargs)
	{
		if (ft_needrsplit(data->lstargs))
		{
			n = ft_nredirsplit(data->lstargs->str);
			if (n)
				ft_splitbyredir(data->lstargs, n);
		}
		data->lstargs->flag = ft_piperedir_flags(data->lstargs->str);
		data->lstargs = data->lstargs->next;
	}
	data->lstargs = data->args_start;
}
