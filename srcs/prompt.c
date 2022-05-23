/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:47:24 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/05/20 17:24:50 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

#define BUFFER_SIZE 42

void	ft_read(int	fd)
{
	char 	buff[BUFFER_SIZE + 1];
	int		i;

	i = 1;
	while (i)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i < 0)
		{
			exit(errno);
		}
		buff[i] = 0;
		printf("%s", buff);
	}
}

void ft_prompt(t_data *data)
{
	char *str;

	while (1)
	{
		str = readline(BLUE "Jean" WHITE "_Mi" RED "Shell>> " WHITE);
		if (ft_strlen(str))
			add_history(str);
		else if (str == NULL)
		{
			printf("exit\n"); // NOTE Gestion de ctrl-d
			ft_exit(0);
		}
		ft_parsing(data, str);
		ft_free_lstargs(data);
		
		int	fd;
		// fd = ft_heredoc(str);
		// if (fd > 0)
			// ft_read(fd);
		// if (!ft_parsing(data, str))
		// printf("error\n");
		// ft_export(str, data);
		// if (!ft_parsing(data, str))
		// printf("error\n");
		free(str);
	}
}
