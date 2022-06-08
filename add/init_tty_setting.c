/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tty_setting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:33:19 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/06/07 15:38:07 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

void	ft_init_tty_setting(t_data *data)
{
	tcgetattr(STDIN_FILENO, &data->saved);
	tcgetattr(STDIN_FILENO, &data->attributes);
	data->attributes.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &data->attributes);
}

void	ft_restore_tty_setting(t_data *data)
{
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &data->saved);
}
