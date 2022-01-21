/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadjigui <sadjigui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:15:05 by sadjigui          #+#    #+#             */
/*   Updated: 2022/01/11 19:08:58 by sadjigui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"

int		main(int ac, char **av, char **env);

void	child(int *pipefd, char **av, char **env);
void	parent(int *pipefd, char **av, char **env);
void	ft_free(char **str);
void	norme(char **all_path, char **exe);
void	norme2(char **exe, char *cmd, char **env);

char	*find_cmd(char *path_cmds, char **exe);
char	*find_path_cmd(char **env);

#endif
