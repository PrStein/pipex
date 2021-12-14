/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadjigui <sadjigui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:05:01 by sadjigui          #+#    #+#             */
/*   Updated: 2021/12/14 16:15:10 by sadjigui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void process_child(int *pipefd, int pipeid, char **av, char **env)
{
    
}

int main(int ac, char **av, char **env)
{
    if (ac == 5)
    {
        int pipefd[2];
        int pipeid;

        if (pipe(pipefd) == -1)
        {
            perror("ERROR ");
            exit(1);
        }
        pipefd = fork();
        if (pipefd == -1)
        {
            perror("ERROR ")
            exit(1);
        }
        if (pipefd == 0)
            process_child(pipefd, pipeid, av, env);
    }
}
