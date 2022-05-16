/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:48:43 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/05/05 14:53:36 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(char *src, char c)
{
	unsigned int	size;
	unsigned int	i;
	char			*tab;

	size = 0;
	i = 0;
	while (src[size] != c && src[size])
		size++;
	tab = ft_calloc(size + 1, sizeof(char));
	if (!tab)
		return (0);
	while (src[i] && src[i] != c)
	{
		tab[i] = src[i];
		i++;
	}
	return (tab);
}

static char	**ft_get_line(const char *s, char c)
{
	int		i;
	int		word;
	int		line;
	char	**dst;

	i = 0;
	word = 0;
	line = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i] && ++word)
			i++;
		if (word > 0 && ++line)
			word = 0;
	}
	dst = ft_calloc(line + 1, sizeof(char *));
	if (!dst)
		return (0);
	return (dst);
}

char	**ft_split(const char *s, char c)
{
	char	**dst;
	int		i;
	int		word;
	int		line;

	i = 0;
	line = 0;
	dst = ft_get_line(s, c);
	if (!dst || !s)
		return (0);
	while (s[i])
	{
		word = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i] && ++word)
			i++;
		if (word > 0)
		{
			dst[line] = ft_strndup((char *)&s[i - word], c);
			if (!dst[line++])
				return (0);
		}
	}
	return (dst);
}
