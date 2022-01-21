/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadjigui <sadjigui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:09:40 by sadjigui          #+#    #+#             */
/*   Updated: 2022/01/11 19:19:16 by sadjigui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
}

void	norme(char **all_path, char **exe)
{
	if (exe[0] == NULL)
	{
		ft_putstr_fd("Command not found : << >>\n", 2);
		ft_free(all_path);
		ft_free(exe);
		exit(1);
	}
	else
		return ;
}

void	norme2(char **exe, char *cmd, char **env)
{
	if (execve(cmd, exe, env) == -1)
	{
		ft_putstr_fd("Command not found : ", 2);
		write(2, exe[0], ft_strlen(exe[0]));
		write(2, "\n", 1);
		ft_free(exe);
		exit(1);
	}
	else
		return ;
}
