/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   JeanMiShell.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:59:28 by ltrinchi          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/05/06 08:29:51 by ltrinchi         ###   ########lyon.fr   */
=======
/*   Updated: 2022/05/05 15:32:59 by mdegraeu         ###   ########.fr       */
>>>>>>> 48204ca62e8ad906c52a6945463d5b87d4b70ad7
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
# include <sys/errno.h>
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
	char			*varname;
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
int		ft_check_varname(char *varname);

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
int		ft_export(char **str, t_data *data);
void	ft_unset(char *str, t_data *data);

/****************************************/
/*---------------PARSING----------------*/
/****************************************/
int		ft_quotes(char *str, int q);
char	**ft_parsing(char *str);
char	*ft_subcpy(char *str, int q);
int		ft_nargs(char *str, int q);

#endif
