/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_pipex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:43:00 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/06/16 13:22:52 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

static int	*ft_init_pipe_array(int nb_pipe)
{
	int	*rtn;
	int	array_size;

	array_size = nb_pipe * 2;
	rtn = ft_calloc(sizeof(int), array_size + 2);
	if (!rtn)
		return (NULL);
	return (rtn);
}

static t_pipex	*ft_exit_struct_pipex(t_pipex *rtn)
{
	ft_free_pipex_struct(rtn);
	return (NULL);
}

static t_pipex	*ft_init_struct_pipex_help(t_data *data, t_pipex *rtn)
{
	rtn->cmd_array->flags_cmd = ft_get_flags_cmd(data, rtn->nb_pipe + 1);
	if (rtn->cmd_array->flags_cmd == NULL)
		return (ft_exit_struct_pipex(rtn));
	rtn->redic_array = ft_get_files(data, rtn->nb_pipe + 1);
	if (rtn->redic_array == NULL)
		return (ft_exit_struct_pipex(rtn));
	rtn->pipe_array = ft_init_pipe_array(rtn->nb_pipe);
	if (rtn->pipe_array == NULL)
		return (ft_exit_struct_pipex(rtn));
	rtn->heredoc_array = ft_init_heredoc(data, rtn->nb_pipe + 1);
	if (rtn->heredoc_array == NULL)
		return (ft_exit_struct_pipex(rtn));
	rtn->fd_in = 0;
	rtn->fd_out = 0;
	return (rtn);
}

t_pipex	*ft_init_struct_pipex(t_data *data)
{
	t_pipex	*rtn;

	rtn = malloc(sizeof(t_pipex));
	if (rtn == NULL)
		return (rtn);
	rtn->env = ft_set_env(data);
	if (rtn->env == NULL)
		return (ft_exit_struct_pipex(rtn));
	rtn->nb_pipe = ft_nb_of_pipe(data);
	rtn->cmd_array = malloc(sizeof(t_cmd));
	if (rtn->cmd_array == NULL)
		return (ft_exit_struct_pipex(rtn));
	rtn->cmd_array->type = ft_calloc(rtn->nb_pipe + 1, sizeof(int));
	if (rtn->cmd_array->type == NULL)
		return (ft_exit_struct_pipex(rtn));
	rtn->cmd_array->path_cmd = ft_get_path_cmd(data, rtn->nb_pipe + 1, rtn->env,
			rtn->cmd_array->type);
	if (rtn->cmd_array->path_cmd == NULL)
		return (ft_exit_struct_pipex(rtn));
	return (ft_init_struct_pipex_help(data, rtn));
}
