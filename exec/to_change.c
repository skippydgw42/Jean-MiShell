/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_change.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:22:18 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/05/23 11:25:33 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/JeanMiShell.h"

int	valid_path(char *av, t_pipex *vars)
{
	char	*path;
	char	*temp;
	int		i;

	i = 0;
	temp = split_flags(av);
	while (vars->env[i])
	{
		path = ft_strjoin(vars->env[i], temp);
		if (access(path, F_OK) == 0)
		{
			free_two_str(temp, path);
			return (1);
		}
		i++;
	}
	free_two_str(temp, path);
	return (0);
}

int	flags_cmd(char **av, t_pipex *vars)
{
	int	i;
	int	j;

	i = 2;
	j = 0;
	vars->f_cmd = malloc(sizeof(char *) * (vars->ac - 1));
	if (!vars->f_cmd)
		return (0);
	while (i < vars->ac)
	{
		vars->f_cmd[j] = ft_strdup(av[i]);
		if (!vars->f_cmd[j])
			return (0);
		i++;
		j++;
	}
	vars->f_cmd[j] = 0;
	return (1);
}

int	paths_cmd(t_pipex *vars)
{
	char	*main_cmd;
	int		i;
	int		j;

	i = -1;
	while (vars->f_cmd[++i])
	{
		main_cmd = split_flags(vars->f_cmd[i]);
		if (!main_cmd)
			return (0);
		j = -1;
		while (vars->env[++j])
		{
			vars->p_cmd[i] = ft_strjoin(vars->env[j], main_cmd);
			if (access(vars->p_cmd[i], X_OK) == 0)
				break ;
			free(vars->p_cmd[i]);
			if (!vars->env[j + 1])
				vars->p_cmd[i] = ft_strdup(main_cmd);
		}
		free(main_cmd);
	}
	vars->p_cmd[i] = 0;
	return (1);
}

int	init_struct(int ac, char **av, char **env, t_pipex *vars)
{
	vars->i = 0;
	vars->ac = ac - 1;
	vars->nb_pipe = vars->ac - 3;
	vars->arr_size = vars->nb_pipe * 2;
	if (!get_files(av, vars))
		return (0);
	if (!get_paths(env, vars))
		return (0);
	if (!flags_cmd(av, vars))
		return (0);
	vars->p_cmd = malloc(sizeof(char *) * (vars->ac));
	if (!vars->p_cmd)
		return (0);
	if (!paths_cmd(vars))
		return (0);
	vars->array = malloc(sizeof(int) * (vars->arr_size));
	if (!vars->array)
		return (0);
	return (1);
}

int	get_files(char **av, t_pipex *vars)
{
	int	i;

	i = 0;
	vars->files = malloc(sizeof(char *) * 3);
	if (!vars->files)
		return (0);
	vars->files[0] = ft_strdup(av[i + 1]);
	while (i < vars->ac)
		i++;
	vars->files[1] = ft_strdup(av[i]);
	vars->files[2] = 0;
	if (!vars->files[0] || !vars->files[1])
		return (0);
	return (1);
}

int	get_paths(char **env, t_pipex *vars)
{
	int	i;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	vars->env = ft_split(&env[i][5], ':');
	if (!vars->env)
		return (0);
	return (1);
}

int	hm_cmd(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
		i++;
	return (i + 1);
}

char	*split_flags(char *av)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (av[i] == ' ' && av[i])
		i++;
	j = i;
	while (av[i] != ' ' && av[i])
		i++;
	str = malloc(sizeof(char) * (i - j + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (av[j] != ' ' && av[j])
	{
		str[i] = av[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	*vars;

	vars = malloc(sizeof(t_pipex) + 1);
	if (!vars)
		return (0);
	if (!parsing(ac, av))
	{
		free(vars);
		return (0);
	}
	if (!init_struct(ac, av, env, vars))
		return (err_a("Error\n", vars));
	init_pipe(vars);
	pipex(vars);
	free_struct(vars);
	return (0);
}
