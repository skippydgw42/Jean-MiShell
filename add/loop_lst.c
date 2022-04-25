/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:07:24 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/04/25 16:22:54 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

void	ft_looplst(t_data *data)
{
	data->start = data->lstenv;
	while (data->lstenv->next)
		data->lstenv = data->lstenv->next;
	data->lstenv->next = data->start;
	data->lstenv = data->start;
}