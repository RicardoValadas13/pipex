/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardovaladas <ricardovaladas@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:00:47 by ricardovala       #+#    #+#             */
/*   Updated: 2023/10/31 14:11:09 by ricardovala      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

/**
 * @brief This function returns the PATH in envp,
	returning 5 char in front to eliminate the "PATH="
 * @param envp The array of enviroment variables
 */
char	*ft_store_path(char **envp)
{
	while (*envp != NULL)
	{
		if (!ft_strncmp("PATH=", *envp, 5))
			return (*envp + 5);
		envp++;
	}
	return (NULL);
}

/**
 * @brief This function does the parsing of the path in envp
 * @param paths The array of the path found in the envp
 * @param args The command to find the path for
 * @returns The path of the given command
 */
char	*ft_get_cmd(char **paths, char *args)
{
	char	*tmp;
	char	*cmd;

	if (!paths)
		return (NULL);
	if (ft_strchr(args, '/') != NULL)
	{
		if (access(args, X_OK | F_OK) == 0)
			return (ft_strdup(args));
		return (NULL);
	}
	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		cmd = ft_strjoin(tmp, args);
		free(tmp);
		if (access(cmd, X_OK | F_OK) == 0)
			return (cmd);
		free(cmd);
		paths++;
	}
	return (NULL);
}
