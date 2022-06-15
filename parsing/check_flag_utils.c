/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:16:46 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/06/15 17:17:47 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

int	ft_piperedir_flags(char *str)
{
	if (!ft_strcmp(str, "|"))
		return (PIPE_F);
	else if (!ft_strcmp(str, "<<"))
		return (HD_F);
	else if (str[0] == '>' || str[0] == '<')
		return (REDIR_F);
	return (STR_F);
}

int	ft_cmdbuilt_flags(char *str)
{
	if (!ft_strcmp(str, "echo"))
		return (BUILT_F);
	else if (!ft_strcmp(str, "cd"))
		return (BUILT_F);
	else if (!ft_strcmp(str, "pwd"))
		return (BUILT_F);
	else if (!ft_strcmp(str, "export"))
		return (BUILT_F);
	else if (!ft_strcmp(str, "unset"))
		return (BUILT_F);
	else if (!ft_strcmp(str, "env"))
		return (BUILT_F);
	else if (!ft_strcmp(str, "exit"))
		return (BUILT_F);
	return (CMD_F);
}
