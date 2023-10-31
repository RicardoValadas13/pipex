/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardovaladas <ricardovaladas@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:12:42 by ricardovala       #+#    #+#             */
/*   Updated: 2023/10/31 14:09:47 by ricardovala      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <libft.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		fd[2];
	int		dup_fd[2];
	char	*path;
	char	**parse_paths;
	char	**parse_args;
	char	*cmd;
	char	**cmd_args;
	int		pid1;
	int		pid2;
	char	*infile_param;
	char	*outfile_param;

}			t_pipex;

int			main(int ac, char **av, char **envp);

char		*ft_store_path(char **envp);
char		*ft_get_cmd(char **paths, char *args);

void		free_childs(t_pipex *pipex);
void		free_parent(t_pipex *pipex);

void		first_child(t_pipex pipex, char **args, char **envp);
void		second_child(t_pipex pipex, char **args, char **envp);

void		error_msg(char *err);
int			msg(char *err);
void		closepipes(int *fds);

#endif