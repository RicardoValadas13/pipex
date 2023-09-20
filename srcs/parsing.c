#include "../inc/pipex.h"
#include "../srcs/libft/libft.h"


/**
 * @brief This function returns the PATH in envp, returning 5 char in front to eliminate the "PATH="
 * @param envp The array of enviroment variables
*/
char*  ft_store_path(char **envp)
{
    while (envp != NULL)
    {
        if (!ft_strncmp("PATH=", *envp, 5))
        return(*envp + 5);
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
char*  ft_parse_args(char **paths, char *args)
{
    char *tmp;
    char *tmp1;
    while (*paths)
    {
        tmp = ft_strjoin(*paths, "/");
        tmp1 = ft_strjoin(tmp, args);
        free(tmp);
        if (access(tmp1, X_OK | F_OK) == -1)    
        return (tmp1); 
        free(tmp1);
        paths++;
    }
    return (NULL) ;
}
/**
 * @brief This function stores in cmd1 and cmd2 the paths of each command
*/
void  ft_parse_cmds(t_pipex pipex, char **args)
{
    pipex.cmd1 = ft_parse_args(pipex.parse_paths, args[2]);
    pipex.cmd2 = ft_parse_args(pipex.parse_paths, args[3]);
    if (pipex.cmd1 != NULL || pipex.cmd2 != NULL)
    {
        //Dont forget to try and put here an exit or something of a kind
        return ;
    }
}