/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pipex_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 09:23:25 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/05/31 15:33:58 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

void	ft_free_pipex_struct(t_pipex *src)
{
	ft_free_dstr(src->env);
	ft_free_dstr(src->path_cmd);
	ft_free_dstr(src->flags_cmd);
	ft_free_dstr(src->files);
	free(src);
}
