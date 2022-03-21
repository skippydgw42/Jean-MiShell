/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:58:04 by mdegraeu          #+#    #+#             */
/*   Updated: 2021/11/10 11:56:38 by mdegraeu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first_elem;
	t_list	*new;

	first_elem = 0;
	if (!lst)
		return (first_elem);
	while (lst)
	{
		new = ft_lstnew((*f)(lst->content));
		if (!new)
		{
			ft_lstclear(&first_elem, del);
			return (first_elem);
		}
		ft_lstadd_back(&first_elem, new);
		lst = lst->next;
		new = new->next;
	}
	new = 0;
	return (first_elem);
}
