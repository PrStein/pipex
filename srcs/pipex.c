/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadjigui <sadjigui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:05:01 by sadjigui          #+#    #+#             */
/*   Updated: 2022/01/11 19:17:31 by sadjigui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*find_path_cmd(char **env)
{
	int	i;

	i = 0;
	while (ft_strncmp(env[i], "PATH=", 5))
		i++;
	return (env[i] + 5);
}

char	*find_cmd(char *path_cmds, char **exe)
{
	char	**all_path;
	char	*the_good_one;
	char	*full_path;
	int		i;
	char	*tmp;

	i = 0;
	all_path = ft_split(path_cmds, ':');
	norme(all_path, exe);
	if (access(exe[0], F_OK) == 0)
		return (exe[0]);
	while (all_path[i])
	{
		the_good_one = ft_strjoin(all_path[i], "/");
		tmp = ft_strdup(the_good_one);
		full_path = ft_strjoin(tmp, exe[0]);
		free(the_good_one);
		free(tmp);
		if (access(full_path, F_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	ft_free(all_path);
	return ("<");
}

void	child(int *pipefd, char **av, char **env)
{
	int		fd;
	char	*path_cmds;
	char	*cmd;
	char	**exe;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		perror("ERROR ");
		exit(1);
	}
	path_cmds = find_path_cmd(env);
	exe = ft_split(av[2], ' ');
	cmd = find_cmd(path_cmds, exe);
	dup2(pipefd[1], 1);
	dup2(fd, 0);
	close(pipefd[0]);
	norme2(exe, cmd, env);
}

void	parent(int *pipefd, char **av, char **env)
{
	int		fd;
	char	*path_cmds;
	char	*cmd;
	char	**exe;

	fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd < 0)
	{
		perror("ERROR ");
		exit(1);
	}
	path_cmds = find_path_cmd(env);
	exe = ft_split(av[3], ' ');
	cmd = find_cmd(path_cmds, exe);
	dup2(pipefd[0], 0);
	dup2(fd, 1);
	close(pipefd[1]);
	norme2(exe, cmd, env);
}

int	main(int ac, char **av, char **env)
{
	int	pipefd[2];
	int	pipeid;

	if (ac == 5)
	{
		if (pipe(pipefd) == -1)
		{
			perror("ERROR ");
			exit(1);
		}
		pipeid = fork();
		if (pipeid < 0)
		{
			perror("ERROR ");
			exit(1);
		}
		if (pipeid == 0)
			child(pipefd, av, env);
		parent(pipefd, av, env);
	}
	if (ac > 5)
		ft_putstr_fd("Too many arguments\n", 2);
	if (ac < 5)
		ft_putstr_fd("Missing arguments\n", 2);
	return (0);
}
