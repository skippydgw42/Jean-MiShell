/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   JeanMiShell.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:59:28 by ltrinchi          #+#    #+#             */
/*   Updated: 2022/04/25 12:11:45 by ltrinchi         ###   ########lyon.fr   */
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
# include <curses.h>
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

// Structures
typedef struct s_env
{
	char			*varName;
	char			*value;
	struct s_env	*next;
}	t_env;

// typedef struct s_data
// {

// }	t_data;

/****************************************/
/*----------------SRCS------------------*/
/****************************************/
void	ft_prompt(void);
int		ft_set_lstenv(char **env, t_env *lstenv);
int		ft_free_lstenv(t_env *lstenv);

/****************************************/
/*--------------BUILTINS----------------*/
/****************************************/
void	ft_echo(char *str, int flag);
void	ft_cd(char *str, t_env *lstenv);
void	ft_pwd(void);

#endif
