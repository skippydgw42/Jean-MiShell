/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pipex_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 09:23:25 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/06/16 11:53:22 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

static void	ft_free_redic_array(t_redic *src, int size_array)
{
	int	i;

	i = 0;
	while (i < size_array)
	{
		free(src[i].input_file);
		free(src[i].output_file);
		i++;
	}
	free(src);
}

void	ft_free_pipex_struct(t_pipex *src)
{
	ft_free_dstr(src->env);
	free(src->cmd_array->type);
	ft_free_dstr(src->cmd_array->path_cmd);
	ft_free_tstr(src->cmd_array->flags_cmd);
	free(src->cmd_array);
	ft_free_redic_array(src->redic_array, src->nb_pipe + 2);
	free(src->pipe_array);
	free(src->heredoc_array);
	free(src);
}
