/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:22:04 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/06/14 15:23:28 by ltrinchi         ###   ########lyon.fr   */
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

int	ft_files(t_data *data, t_pipex *vars)
{
	int		i;
	int		type;
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
		if (start->flag == REDIR_F || start->flag == HD_F)
		{
			type = ft_get_type(start->str);
			start = start->next;
			if (type == INPUT_P)
			{
				if (vars->fd_in != 0)
					close(vars->fd_in);
				vars->fd_in = open(start->str, O_RDONLY);
				if (vars->fd_in < 0)
					return (false);
			}
			if (type == HEREDOC_P)
			{
				vars->fd_in = vars->heredoc_array[vars->i];
			}
			if (type == OUTPUT_P)
			{
				if (vars->fd_out != 0)
					close(vars->fd_out);
				vars->fd_out = open(start->str, O_TRUNC | O_WRONLY | O_CREAT,
						0666);
				if (vars->fd_out < 0)
					return (false);
			}
			if (type == OUTPUT_APPEND_P)
			{
				if (vars->fd_out != 0)
					close(vars->fd_out);
				vars->fd_out = open(start->str, O_APPEND | O_WRONLY | O_CREAT,
						0666);
				if (vars->fd_out < 0)
					return (false);
			}
		}
		start = start->next;
		if (!start || start->flag == PIPE_F)
			break ;
	}
	return (true);
}
