/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:22:04 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/06/20 10:36:11 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

static int	ft_get_type(char *str)
{
	if (ft_strcmp(str, "<") == 0)
		return (INPUT_P);
	if (ft_strcmp(str, "<<") == 0)
		return (HEREDOC_P);
	if (ft_strcmp(str, ">") == 0)
		return (OUTPUT_P);
	if (ft_strcmp(str, ">>") == 0)
		return (OUTPUT_APPEND_P);
	return (false);
}

static int	ft_files_help(t_args *start, t_pipex *vars)
{
	int	type;

	if (start->flag == REDIR_F || start->flag == HD_F)
	{
		type = ft_get_type(start->str);
		start = start->next;
		if (vars->fd_in != 0 && type != HEREDOC_P && type != OUTPUT_P
			&& type != OUTPUT_APPEND_P)
			close(vars->fd_in);
		if (type == INPUT_P)
			vars->fd_in = open(start->str, O_RDONLY);
		if (type == HEREDOC_P)
			vars->fd_in = vars->heredoc_array[vars->i];
		if (type == OUTPUT_P)
			vars->fd_out = open(start->str, O_TRUNC | O_WRONLY | O_CREAT, 0666);
		if (type == OUTPUT_APPEND_P)
			vars->fd_out = open(start->str, O_APPEND | O_WRONLY | O_CREAT,
					0666);
		if (vars->fd_out < 0 || vars->fd_in < 0)
			return (false);
	}
	return (true);
}

int	ft_files(t_data *data, t_pipex *vars)
{
	int		i;
	t_args	*start;

	i = 0;
	start = data->args_start;
	while (i < vars->i)
	{
		start = start->next;
		if (start->flag == PIPE_F)
			i++;
	}
	while (start)
	{
		if (ft_files_help(start, vars) == false)
		{
			return (false);
		}
		start = start->next;
		if (!start || start->flag == PIPE_F)
			break ;
	}
	return (true);
}
