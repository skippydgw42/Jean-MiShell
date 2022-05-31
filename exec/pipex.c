/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:12:35 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/05/23 17:54:39 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

int	ft_exec_process(t_pipex *vars)
{
	char	**cflags;

	cflags = ft_get_flags(vars->f_cmd[vars->i]);
	if (!cflags)
		return (err_mess("cflags_c Error\n", cflags));
	if (execve(vars->p_cmd[vars->i], cflags, vars->env) == -1)
	{
		ft_free_dstr(cflags);
		exit (p_error("C_Process: Command not found"));
	}
	return (1);
}

int	ft_pipexec(t_pipex *vars)
{
	if (vars->i == 0)
	{
		dup2(vars->fd, STDIN_FILENO);
		dup2(vars->array[1], STDOUT_FILENO);
		close(vars->fd);
	}
	else if (vars->i != 0 && vars->i < vars->nb_pipe)
	{
		dup2(vars->array[vars->i * 2 - 2], STDIN_FILENO);
		dup2(vars->array[vars->i * 2 + 1], STDOUT_FILENO);
	}
	else
	{
		dup2(vars->array[vars->i * 2 - 2], STDIN_FILENO);
		dup2(vars->fd, STDOUT_FILENO);
		close(vars->fd);
	}
	ft_close_pipe(vars);
	ft_exec_process(vars);
	return (1);
}

int	ft_pipex(t_pipex *vars)
{
	int	pid;

	while (vars->i <= vars->nb_pipe)
	{
		pid = fork();
		if (pid == 0)
		{
			if (vars->i == 0)
			{
				vars->fd = open(vars->files[0], O_RDONLY);
				if (vars->fd < 0)
					return (0);
			}
			if (vars->i == vars->nb_pipe)
			{
				vars->fd = open(vars->files[1], O_TRUNC | O_WRONLY
						| O_CREAT, 0666);
				if (vars->fd < 0)
					return (0);
			}
			ft_pipexec(vars);
		}
		vars->i++;
	}
	return (1);
}
