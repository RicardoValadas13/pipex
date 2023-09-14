/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:12:42 by ricardovala       #+#    #+#             */
/*   Updated: 2023/09/14 13:54:04 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "../srcs/libft/libft.h"

void  ft_check_args(char **args, char **envp);
int main(int ac,char **av, char **envp);
char*  ft_store_path(char **envp);

typedef struct s_pipex
{
  int infile;
  int outfile;
  int fd[2];
  char *path;
  char **parse_paths;
  char **parse_args;
  
}t_pipex;


#endif