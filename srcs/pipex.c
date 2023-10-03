/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardovaladas <ricardovaladas@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:00:54 by ricardovala       #+#    #+#             */
/*   Updated: 2023/10/03 11:09:11 by ricardovala      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"
#include "../srcs/libft/libft.h"

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;

	if (ac != 5)
		return (msg("Wrong format: ./pipex infile cmd1 cmd2 outfile\n"));
	pipex.infile = open(av[1], O_RDONLY);
	if (pipex.infile < 0)
		error_msg("Infile");
	pipex.outfile = open(av[ac - 1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (pipex.outfile < 0)
		error_msg("Outfile");
	if (pipe(pipex.fd) < 0)
		error_msg("Pipe");
	pipex.path = ft_store_path(envp);
	pipex.parse_paths = ft_split(pipex.path, ':');
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		first_child(pipex, av, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		second_child(pipex, av, envp);
	closepipes(&pipex);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	free_parent(&pipex);
	return (0);
}
