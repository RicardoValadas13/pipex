/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardovaladas <ricardovaladas@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:02:37 by ricardovala       #+#    #+#             */
/*   Updated: 2023/10/31 14:12:42 by ricardovala      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

/**
 * @brief This function cleans all the alocated memory from a certain array
 * @param parse the array thats gonna be cleaned
 */
void	free_parent(t_pipex *pipex)
{
	close(pipex->outfile);
	close(pipex->infile);
}

/**

	*  @brief This function serves the purpose to 
	free the alocated memory in the child processes
 * @param pipex A pointer to the structure where the memory was allocated
 */
void	free_childs(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->cmd_args && pipex->cmd_args[i])
	{
		free(pipex->cmd_args[i]);
		i++;
	}
	free(pipex->cmd_args);
	free(pipex->cmd);
	i = 0;
	while (pipex->parse_paths && pipex->parse_paths[i])
	{
		free(pipex->parse_paths[i]);
		i++;
	}
	free(pipex->parse_paths);
}

void	closepipes(int *fd)
{
	close(fd[0]);
	close(fd[1]);
}
