#include "../inc/pipex.h"
#include "../srcs/libft/libft.h"

/**
 * @brief This function clean all the alocated memory from a certain array
 * @param parse the array thats gonna be cleaned
*/
void  ft_clean(char **parse)
{
    int i;

    i = 0;
    while(parse[i] != NULL)
        free (parse[i++]);  
    free(parse);
}

int main(int ac,char **av, char **envp)
{
    t_pipex pipex;
    
    if (ac != 5)
        return ; 
    pipex.infile = open(av[1], O_RDONLY);
    if (pipex.infile < 0)
        return ;
    pipex.outfile = open(av[4],O_CREAT , O_WRONLY);
    if (pipex.outfile < 0)
        return ;
    if(pipe(pipex.fd) < 0)
        return ;
    pipex.path = ft_store_path(envp); 
    pipex.parse_paths = ft_split(pipex.path, ':');
    ft_parse_cmds(pipex, av);
    ft_clean(pipex.parse_paths);
    first_child(pipex, av, envp);
    second_child(pipex, av, envp);
    close(pipex.fd[0]);
    close(pipex.fd[1]);
    waitpid(pipex.pid1, NULL, 0);
    waitpid(pipex.pid2, NULL, 0);
}

