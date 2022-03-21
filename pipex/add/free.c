/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:23:15 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/03/18 13:17:52 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_two_str(char *str1, char *str2)
{
	if (str1)
		free(str1);
	if (str2)
		free(str2);
}

void	free_doubleptr(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i])
				free(str[i]);
			i++;
		}
		free(str);
	}
}

void	free_struct(t_struct *vars)
{
	if (vars->files)
		free_doubleptr(vars->files);
	if (vars->env)
		free_doubleptr(vars->env);
	if (vars->f_cmd)
		free_doubleptr(vars->f_cmd);
	if (vars->p_cmd)
		free_doubleptr(vars->p_cmd);
	if (vars->array)
		free(vars->array);
	free(vars);
}
