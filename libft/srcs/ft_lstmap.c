/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:09:45 by ltrinchi          #+#    #+#             */
/*   Updated: 2021/11/13 17:26:21 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*buff;

	new = NULL;
	while (lst)
	{
		buff = ft_lstnew((*f)(lst->content));
		if (!buff)
		{
			ft_lstclear(&new, (*del));
			return (new);
		}
		ft_lstadd_back(&new, buff);
		lst = lst->next;
	}
	return (new);
}
