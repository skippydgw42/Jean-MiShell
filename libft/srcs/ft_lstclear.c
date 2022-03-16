/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:30:26 by ltrinchi          #+#    #+#             */
/*   Updated: 2021/11/13 16:01:14 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr;

	while ((*lst))
	{
		ptr = (*lst);
		(*del)((*lst)->content);
		(*lst) = (*lst)->next;
		free(ptr);
	}
	*lst = NULL;
}
