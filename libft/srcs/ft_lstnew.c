/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 09:22:20 by ltrinchi          #+#    #+#             */
/*   Updated: 2021/11/13 09:35:09 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*var;

	var = malloc(sizeof(t_list));
	if (!var)
		return (0);
	var->next = 0;
	var->content = content;
	return (var);
}
