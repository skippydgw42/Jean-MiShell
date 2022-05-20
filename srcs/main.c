/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:58:35 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/05/20 15:23:59 by mdegraeu         ###   ########.fr       */
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
	data->env_start = data->lstenv;

	// TODO Creer une fonction Init
	// NOTE Gestion de l'affichage du ^C
	tcgetattr(STDIN_FILENO, &data->saved);
	tcgetattr(STDIN_FILENO, &data->attributes);
	data->attributes.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &data->attributes);

	ft_prompt(data);

	ft_free_data(data);
	return (0);
}
