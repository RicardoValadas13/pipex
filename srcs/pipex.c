#include "../inc/pipex.h"
#include "../srcs/libft/libft.h"

/**
 * @brief This function writes the err (2) the error msg
 * @param err The msg to be written
*/
int error_msg(char *err)
{
    write(2, err, ft_strlen(err));
    return (1);
}
/**
 * @brief This function cleans all the alocated memory from a certain array
 * @param parse the array thats gonna be cleaned
*/
void  clean_parent(t_pipex  *pipex)
{
    int i;

    i = 0;
    while(pipex->parse_paths[i])
    {
        free(pipex->parse_paths[i]);
        i++; 
    }
    free(pipex->parse_paths);
}
void    closepipes(t_pipex *pipex)
{
    close(pipex->fd[0]);
    close(pipex->fd[1]);
}
int main(int ac,char **av, char **envp)
{
    t_pipex pipex;
    
    if (ac != 5)
        return(error_msg("!Format!")) ; 
    pipex.infile = open(av[1], O_RDONLY);
    if (pipex.infile < 0)
        error_msg("Infile");
    pipex.outfile = open(av[ac - 1],O_TRUNC | O_CREAT | O_RDWR, 0000644);
    if (pipex.outfile < 0)
        error_msg("Outfile");
    if(pipe(pipex.fd) < 0)
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
    clean_parent(&pipex);
    return (0);
}

