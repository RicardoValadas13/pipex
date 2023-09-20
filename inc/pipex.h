/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardovaladas <ricardovaladas@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:12:42 by ricardovala       #+#    #+#             */
/*   Updated: 2023/09/20 14:56:40 by ricardovala      ###   ########.fr       */
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
void  ft_clean(char **parse);
void  ft_parse_cmds(t_pipex pipex, char **args);

typedef struct s_pipex
{
  int infile;
  int outfile;
  int fd[2];
  char *path;
  char **parse_paths;
  char **parse_args;
  char *cmd1;
  char *cmd2;
  int pid1;
  int pid2;
  
}t_pipex;


#endif