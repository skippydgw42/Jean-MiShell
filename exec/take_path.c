/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_path_cmd_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:20:10 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/06/16 11:20:59 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

char	*ft_take_path(char *cmd, char **env)
{
	int		i;
	char	*path;
	char	**list_path;
	char	*ptr;

	i = 0;
	path = NULL;
	list_path = ft_split_path(env);
	if (list_path == NULL)
		return (NULL);
	while (list_path[i])
	{
		path = ft_strjoin("/", cmd);
		ptr = path;
		path = ft_strjoin(list_path[i++], path);
		free(ptr);
		if (access(path, X_OK) == 0)
		{
			ft_free_dstr(list_path);
			return (path);
		}
		free(path);
	}
	ft_free_dstr(list_path);
	return (NULL);
}
