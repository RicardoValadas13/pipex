/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardovaladas <ricardovaladas@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:00:37 by ricardovala       #+#    #+#             */
/*   Updated: 2023/10/31 14:12:19 by ricardovala      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

/**

	* @brief This function handles the beggining part 
	of the pipe where the first command happens
 * @param pipex The struct where evrythig is stored
 * @param args The arguments given in the terminal
 * @param envp The enviroment variables array
 */
void	first_child(t_pipex pipex, char **args, char **envp)
{
	pipex.infile = open(pipex.infile_param, O_RDONLY);
	if (pipex.infile < 0)
		error_msg("Infile");
	pipex.dup_fd[1] = dup2(pipex.infile, STDIN_FILENO);
	close(pipex.infile);
	pipex.dup_fd[0] = dup2(pipex.fd[1], STDOUT_FILENO);
	close(pipex.fd[1]);
	close(pipex.fd[0]);
	pipex.cmd_args = ft_split(args[2], ' ');
	pipex.parse_paths = ft_split(pipex.path, ':');
	pipex.cmd = ft_get_cmd(pipex.parse_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		closepipes(pipex.dup_fd);
		free_childs(&pipex);
		exit(msg("Command not found\n"));
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
	closepipes(pipex.dup_fd);
	free_childs(&pipex);
	error_msg("execve");
}

/**

	* @brief This function handles the end part of 
	the pipe where the second command happens
 * @param pipex The struct where evrythig is stored
 * @param args The arguments given in the terminal
 * @param envp The enviroment variables array
 */
void	second_child(t_pipex pipex, char **args, char **envp)
{
	pipex.outfile = open(pipex.outfile_param, O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (pipex.outfile < 0)
		error_msg("Outfile");
	pipex.dup_fd[0] = dup2(pipex.fd[0], STDIN_FILENO);
	close(pipex.fd[0]);
	pipex.dup_fd[1] = dup2(pipex.outfile, STDOUT_FILENO);
	close(pipex.outfile);
	close(pipex.fd[1]);
	pipex.cmd_args = ft_split(args[3], ' ');
	pipex.parse_paths = ft_split(pipex.path, ':');
	pipex.cmd = ft_get_cmd(pipex.parse_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		closepipes(pipex.dup_fd);
		free_childs(&pipex);
		exit(msg("Command not found\n"));
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
	closepipes(pipex.dup_fd);
	free_childs(&pipex);
	error_msg("execve");
}
