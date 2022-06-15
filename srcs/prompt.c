/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:47:24 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/06/15 17:12:27 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

size_t	ft_checkwspace(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 32)
			i++;
		else if (str[i] >= 9 && str[i] <= 13)
			i++;
		else
			break ;
	}
	return (i);
}

void	ft_prompt(t_data *data)
{
	char	*str;

	while (1)
	{
		ft_init_tty_setting(data);
		ft_set_signal_prompt();
		str = readline(BLUE "Jean" WHITE "_Mi" RED "Shell>> " WHITE);
		ft_restore_tty_setting(data);
		if (ft_strlen(str))
		{
			add_history(str);
			if (ft_checkwspace(str) < ft_strlen(str))
			{
				if (ft_parsing(data, str) == true)
					ft_exec(data);
				ft_free_lstargs(data);
			}
		}
		else if (str == NULL)
		{
			printf("exit\n");
			exit(0);
		}
		free(str);
	}
}
