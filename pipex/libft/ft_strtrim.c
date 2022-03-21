/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:35:30 by mdegraeu          #+#    #+#             */
/*   Updated: 2021/11/10 12:08:18 by mdegraeu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_str_size(char const *s, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	ct;

	i = 0;
	j = ft_strlen(s) - 1;
	ct = 0;
	if (ft_strlen(s) == 0)
		return (1);
	while (ft_strchr(set, s[i]) && s[i])
	{
		i++;
		ct++;
	}
	while (ft_strchr(set, s[j]) && i < j)
	{
		j--;
		ct++;
	}
	return (ft_strlen(s) - ct);
}

char	*ft_strtrim(char const *s, char const *set)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	str = ft_calloc(ft_str_size(s, set) + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (ft_strchr(set, s[i]) && s[i])
		i++;
	if (ft_strlen(s) > 0)
	{
		while (j < ft_str_size(s, set))
		{
			str[j] = s[i];
			i++;
			j++;
		}
	}
	str[j] = '\0';
	return (str);
}
