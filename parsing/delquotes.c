/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delquotes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:52:49 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/06/17 14:23:08 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

int	ft_quotestodel(char *str)
{
	int	i;
	int	q;
	int	del;

	i = 0;
	q = 0;
	del = 0;
	while (str[i])
	{
		if (ft_quotes(str[i], q) != q)
			del++;
		q = ft_quotes(str[i], q);
		i++;
	}
	return (del);
}

void	ft_cpywithoutquotes_help(char *str, char *dst)
{
	int	i;
	int	j;
	int	q;

	i = 0;
	j = 0;
	q = 0;
	while (str[i])
	{
		if (ft_quotes(str[i], q) != q)
		{
			q = ft_quotes(str[i], q);
			i++;
		}
		else
		{
			dst[j] = str[i];
			j++;
			i++;
		}
	}
	dst[j] = '\0';
}

char	*ft_cpywithoutquotes(char *str, int del)
{
	int		i;
	int		j;
	int		q;
	char	*dst;

	i = 0;
	j = 0;
	q = 0;
	dst = malloc(sizeof(char) * (ft_strlen(str) - del + 1));
	if (!dst)
		return (NULL);
	ft_cpywithoutquotes_help(str, dst);
	return (dst);
}

int	ft_delquotes(t_data *data)
{
	int		i;
	int		del;
	char	*dst;

	i = 0;
	del = 0;
	while (data->lstargs)
	{
		del = ft_quotestodel(data->lstargs->str);
		if (del)
		{	
			dst = ft_cpywithoutquotes(data->lstargs->str, del);
			if (!dst)
				return (0);
			free(data->lstargs->str);
			data->lstargs->str = dst;
		}
		data->lstargs = data->lstargs->next;
	}
	data->lstargs = data->args_start;
	return (1);
}
