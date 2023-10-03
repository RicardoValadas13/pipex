/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardovaladas <ricardovaladas@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:02:37 by ricardovala       #+#    #+#             */
/*   Updated: 2023/10/03 11:03:33 by ricardovala      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"
#include "../srcs/libft/libft.h"

/**
 * @brief This function cleans all the alocated memory from a certain array
 * @param parse the array thats gonna be cleaned
 */
void	free_parent(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->parse_paths[i])
	{
		free(pipex->parse_paths[i]);
		i++;
	}
	free(pipex->parse_paths);
}
/**

	*  @brief This function serves the purpose to free the alocated memory in the child processes
 * @param pipex A pointer to the structure where the memory was allocated
 */
void	free_childs(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->cmd_args[i])
	{
		free(pipex->cmd_args[i]);
		i++;
	}
	free(pipex->cmd_args);
	free(pipex->cmd);
}

void	closepipes(t_pipex *pipex)
{
	close(pipex->fd[0]);
	close(pipex->fd[1]);
}
