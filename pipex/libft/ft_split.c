/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:24:03 by mdegraeu          #+#    #+#             */
/*   Updated: 2021/11/12 11:33:31 by mdegraeu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_split_count(char const *s, char c)
{
	unsigned int	i;
	unsigned int	ct;

	i = 0;
	ct = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			ct++;
		while (s[i] != c && s[i])
			i++;
	}
	return (ct);
}

void	ft_free_tab(char **split, const char *str, char c)
{
	unsigned int	i;
	unsigned int	size;

	i = 0;
	size = ft_split_count(str, c);
	while (i < size)
	{
		if (split[i])
			free(split[i]);
		i++;
	}
	free(split);
}

static int	ft_lit_str(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static char	*ft_cpy_str(char const *s, char c, unsigned int i)
{
	unsigned int	j;
	char			*str;

	j = 0;
	str = ft_calloc(ft_lit_str(&s[i], c) + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (s[i] != c && s[i])
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	i;
	unsigned int	k;
	char			**split;

	i = 0;
	k = -1;
	if (!s)
		return (NULL);
	split = ft_calloc(ft_split_count(s, c) + 1, sizeof(char *));
	if (!split)
		return (NULL);
	while (++k < ft_split_count(s, c))
	{
		while (s[i] == c && s[i])
			i++;
		split[k] = ft_cpy_str(s, c, i);
		if (!split[k])
		{
			ft_free_tab(split, s, c);
			return (NULL);
		}
		while (s[i] != c && s[i])
			i++;
	}
	return (split);
}
