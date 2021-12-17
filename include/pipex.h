/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadjigui <sadjigui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:15:05 by sadjigui          #+#    #+#             */
/*   Updated: 2021/12/17 01:41:41 by sadjigui         ###   ########.fr       */
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


int    main(int ac, char **av, char **env);

void	child(int *pipefd, char **av, char **env);
void	parent(int *pipefd, char **av, char **env);

char	*find_cmd(char *path_cmds, char **exe);
char	*find_path_cmd(char **env);

#endif
