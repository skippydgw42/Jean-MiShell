/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   JeanMiShell.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:59:28 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/04/26 12:04:57 by ltrinchi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef JEANMISHELL_H
# define JEANMISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <signal.h>
# include <dirent.h>
# include <termios.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/srcs/libft.h"

// Printf Colors
# define RED "\033[0;31m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"
# define GREEN "\033[0;32m"

typedef enum e_boolean
{
	false,
	true
}	t_boolean;

// Structures
typedef struct s_env
{
	char			*varName;
	char			*value;
	t_boolean		is_export;
	struct s_env	*next;
}	t_env;

typedef struct s_data
{
	t_env	*lstenv;
	t_env	*start;
}	t_data;

/****************************************/
/*-----------------ADD------------------*/
/****************************************/
int		ft_free_dstr(char **str);
int		ft_free_lstenv(t_data *data);

/****************************************/
/*----------------SRCS------------------*/
/****************************************/
void	ft_prompt(void);
t_env	*ft_set_lstenv(char **env);

/****************************************/
/*--------------BUILTINS----------------*/
/****************************************/
void	ft_echo(char *str, int flag);
void	ft_cd(char *str, t_env *lstenv);
void	ft_pwd(void);
int		ft_env(t_data *data);


#endif
