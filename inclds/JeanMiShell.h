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

# define PIPE_F 0
# define CMD_F 1
# define BUILT_F 2
# define REDIR_F 3
# define HD_F 4
# define FILE_F 5
# define STR_F 6

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

typedef struct s_args
{
	char			*str;
	int				flag;
	struct s_args	*next;
}	t_args;

typedef struct s_pipex
{
	// int		ac;
	// char	**files;
	// char	**f_cmd;
	// char	**p_cmd;
	// int		*array;
	// int		arr_size;
	// int		fd;
	int		i;
	int		nb_pipe;
	char	**env;
	char	**path_cmd;
	char	**flags_cmd;
}	t_pipex;

typedef struct s_data
{
	t_env			*lstenv;
	t_env			*env_start;
	t_args			*lstargs;
	t_args			*args_start;
	struct termios	saved;
	struct termios	attributes;
}	t_data;

/****************************************/
/*-----------------ADD------------------*/
/****************************************/
int		ft_free_dstr(char **str);
int		ft_free_data(t_data *data);
int		ft_free_lstargs(t_data *data);
int		ft_check_varname(char *varname);
void	ft_signal_handler(int sig);
void	ft_exit(t_data *data);

/****************************************/
/*----------------SRCS------------------*/
/****************************************/
void	ft_prompt(t_data *data);
t_env	*ft_set_lstenv(char **env);
int		ft_heredoc(char *delimiter);

/****************************************/
/*--------------BUILTINS----------------*/
/****************************************/
void	ft_echo(char *str, int flag);
void	ft_cd(char *str, t_env *lstenv);
void	ft_pwd(void);
int		ft_env(t_data *data);
int		ft_export(char **str, t_data *data);
void	ft_unset(char **str, t_data *data);

/****************************************/
/*---------------PARSING----------------*/
/****************************************/
int		ft_quotes(char c, int q);
void	ft_subcpy(t_args *new, char *str);
int		ft_nargs(char *str);
int		ft_is_close(char *str);
void	ft_preparsing(t_args **lstargs, char *str);
int		ft_parsing(t_data *data, char *str);
void	ft_postpars(t_data *data);

int		ft_needreplace(char *str);
void	ft_replace(t_data *data, t_args *args);
char	*ft_find_varname(char *str, int q);
int		ft_finddellen(char *str);
int		ft_findaddlen(t_data *data, char *str);
int		ft_rollst(t_env **lst, char *str, int q);
int		ft_separator(char c);

char	*ft_cpytopipe(char *str, int q);
int		ft_lentopipe(char *str, int q);
int		ft_npipe(char *str);
void	ft_secondsplitlst(t_data *data);
void	ft_thirdsplitlst(t_data *data);
void	ft_flag(t_data *data);
int		ft_piperedir_flags(char *str);

int		ft_parserr(t_data *data);

/****************************************/
/*-----------------EXEC-----------------*/
/****************************************/
int		ft_exec(t_data *data);
void	ft_free_pipex_struct(t_pipex *src);
int		ft_nb_of_pipe(t_data *data);

#endif
