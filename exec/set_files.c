/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:49:32 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/06/17 15:32:09 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

static int	ft_get_type(char *str, int *input_type, int *output_type)
{
	if (ft_strcmp(str, "<") == 0)
	{
		*input_type = INPUT_P;
		return (INPUT_P);
	}
	if (ft_strcmp(str, "<<") == 0)
	{
		*input_type = HEREDOC_P;
		return (HEREDOC_P);
	}
	if (ft_strcmp(str, ">") == 0)
	{
		*output_type = OUTPUT_P;
		return (OUTPUT_P);
	}
	if (ft_strcmp(str, ">>") == 0)
	{
		*output_type = OUTPUT_APPEND_P;
		return (OUTPUT_APPEND_P);
	}
	return (false);
}

static void	ft_get_file_help_help(t_args *start, t_redic *rtn, int *i)
{
	int		type;
	char	*ptr;

	type = 0;
	if (type == HEREDOC_P)
	{
		ptr = rtn[*i].input_file;
		rtn[*i].input_file = NULL;
		free(ptr);
	}
	if (type == OUTPUT_P || type == OUTPUT_APPEND_P)
	{
		ptr = rtn[*i].output_file;
		rtn[*i].output_file = ft_strdup(start->str);
		free(ptr);
	}
	if (start->flag == PIPE_F)
	{
		(*i)++;
		rtn[*i].input_type = 0;
		rtn[*i].output_type = 0;
		rtn[*i].input_file = NULL;
		rtn[*i].output_file = NULL;
	}
}

static void	ft_get_file_help(t_args *start, t_redic *rtn, int *i)
{
	int		type;
	char	*ptr;

	type = 0;
	if (start->flag == REDIR_F || start->flag == HD_F)
	{
		type = ft_get_type(start->str, &rtn[*i].input_type,
				&rtn[*i].output_type);
		start = start->next;
	}
	if (type == INPUT_P)
	{
		ptr = rtn[*i].input_file;
		rtn[*i].input_file = ft_strdup(start->str);
		free(ptr);
	}
	ft_get_file_help_help(start, rtn, i);
}

t_redic	*ft_get_files(t_data *data, int nb_cmd)
{
	int		i;
	t_redic	*rtn;
	t_args	*start;
	int		type;

	i = 0;
	rtn = ft_calloc(nb_cmd + 1, sizeof(t_redic));
	if (rtn == NULL)
		return (NULL);
	start = data->args_start;
	rtn[i].input_type = 0;
	rtn[i].output_type = 0;
	rtn[i].input_file = NULL;
	rtn[i].output_file = NULL;
	type = 0;
	while (start)
	{
		ft_get_file_help(start, rtn, &i);
		start = start->next;
	}
	return (rtn);
}
