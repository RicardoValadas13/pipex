/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardovaladas <ricardovaladas@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:12:42 by ricardovala       #+#    #+#             */
/*   Updated: 2023/10/03 11:08:24 by ricardovala      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../srcs/libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		fd[2];
	char	*path;
	char	**parse_paths;
	char	**parse_args;
	char	*cmd;
	char	**cmd_args;
	int		pid1;
	int		pid2;

}			t_pipex;

int			main(int ac, char **av, char **envp);

char		*ft_store_path(char **envp);
char		*ft_get_cmd(char **paths, char *args);

void	  free_childs(t_pipex *pipex);
void		free_parent(t_pipex *pipex);

void		first_child(t_pipex pipex, char **args, char **envp);
void		second_child(t_pipex pipex, char **args, char **envp);

int			error_msg(char *err);
int			msg(char *err);
void		closepipes(t_pipex *pipex);

#endif