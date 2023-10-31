/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardovaladas <ricardovaladas@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:00:54 by ricardovala       #+#    #+#             */
/*   Updated: 2023/10/10 18:30:51 by ricardovala      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;

	if (ac != 5)
		return (msg("Wrong format: ./pipex infile cmd1 cmd2 outfile\n"));
	if (pipe(pipex.fd) < 0)
		error_msg("Pipe");
	pipex.infile_param = av[1];
	pipex.outfile_param = av[ac - 1];
	pipex.path = ft_store_path(envp);
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		first_child(pipex, av, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		second_child(pipex, av, envp);
	closepipes(pipex.fd);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	return (0);
}
