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

int	exit_status(int pid1status, int pid2status)
{
	if (WIFEXITED(pid1status) != 0)
		exit(WEXITSTATUS(pid1status));
	else if (WIFEXITED(pid2status) != 0)
		exit(WEXITSTATUS(pid2status));
	else
		exit(0);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;
	int		pid1status;
	int		pid2status;

	if (ac != 5)
		return(msg("Wrong format: ./pipex infile cmd1 cmd2 outfile\n"));
	if (pipe(pipex.fd) < 0)
		return(msg("Pipe\n"));
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
	waitpid(pipex.pid1, &pid1status, 0);
	waitpid(pipex.pid2, &pid2status, 0);
	exit_status(pid1status, pid2status);
	return (0);
}
