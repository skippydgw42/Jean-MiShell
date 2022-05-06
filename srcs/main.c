/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:58:35 by ltrinchi          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/05/05 16:31:19 by ltrinchi         ###   ########lyon.fr   */
=======
/*   Updated: 2022/05/05 15:33:31 by mdegraeu         ###   ########.fr       */
>>>>>>> 48204ca62e8ad906c52a6945463d5b87d4b70ad7
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

void	ft_text_color(int i)
{
	if (i == 1)
	{
		printf(GREEN);
	}
}

int	main(int ac, char **av, char **env)
{
	t_data	*data;
	int		i;

	(void)ac;
	(void)av;
	data = malloc(sizeof(t_data));
	if (!data)
	{
		perror("Error:");
		return (errno);
	}
	data->lstenv = ft_set_lstenv(env);
	data->start = data->lstenv;
	ft_prompt();
	ft_free_lstenv(data);
	return (0);
}
