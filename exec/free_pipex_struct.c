/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pipex_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 09:23:25 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/05/31 14:09:30 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

void	ft_free_pipex_struct(t_pipex *src)
{
	ft_free_dstr(src->env);
	ft_free_dstr(src->path_cmd);
	ft_free_dstr(src->flags_cmd);
	free(src);
}
