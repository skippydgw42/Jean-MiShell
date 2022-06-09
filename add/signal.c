/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:55:35 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/06/09 16:19:09 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

void	ft_signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

static void	ft_signal_handler_fork(int sig)
{
	if (sig == SIGINT)
		printf("\n");
}

void	ft_set_signal_prompt(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, ft_signal_handler);
}

void	ft_set_signal_parent(void)
{
	signal(SIGQUIT, ft_signal_handler_fork);
	signal(SIGINT, ft_signal_handler_fork);
}

void	ft_set_signal_child(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}
