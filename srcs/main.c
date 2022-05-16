/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:58:35 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/05/16 10:22:44 by ltrinchi         ###   ########lyon.fr   */
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

int main(int ac, char **av, char **env)
{
	t_data *data;

	(void)ac;
	(void)av;

	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, ft_signal_handler);

	data = malloc(sizeof(t_data));
	if (!data)
	{
		perror("Error:");
		return (errno);
	}
	data->lstenv = ft_set_lstenv(env);
	data->start = data->lstenv;

	// TODO Creer une fonction Init
	// NOTE Gestion de l'affichage du ^C
	tcgetattr(STDIN_FILENO, &data->saved);
	tcgetattr(STDIN_FILENO, &data->attributes);
	data->attributes.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &data->attributes);

	ft_prompt(data);

	ft_free_lstenv(data);
	return (0);
}
