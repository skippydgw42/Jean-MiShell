/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fourthsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:57:36 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/06/15 14:29:35 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

void    ft_fourthsplitlst(t_data *data)
{
    int exp;

    exp = 0;
    while (data->lstargs)
    {
        if (data->lstargs->flag == PIPE_F && ft_strcmp(data->lstargs->str, "|"))
            data->lstargs->flag = STR_F;
        if (data->lstargs->flag == BUILT_F)
        {
            // if (!ft_strcmp(data->lstargs->str, "export"))
                exp = 1;
        }
        if (data->lstargs->flag == PIPE_F)
            exp = 0;
        if (exp == 0)
        {
            exp = ft_needsplit(data->lstargs->str);
            if (exp)
                ft_splitlst(data->lstargs, exp);
        }
        data->lstargs = data->lstargs->next;
    }
    data->lstargs = data->args_start;
}
