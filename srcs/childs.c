#include "../inc/pipex.h"
#include "../srcs/libft/libft.h"

/**
 * @brief This function handles the beggining part of the pipe where the first command happens
 * @param pipex The struct where evrythig is stored
 * @param args The arguments given in the terminal 
 * @param envp The enviroment variables array
*/
void  first_child(t_pipex pipex, char **args, char**envp)
{
  pipex.pid1 = fork();
  if (pipex.pid1 < 0)
    return ;
  if (pipex.pid1 == 0)
  {
    dup2(pipex.fd[1], STDOUT_FILENO);
    close(pipex.fd[0]);  
    dup2(pipex.infile, 0);
    close(pipex.fd[1]);
    execve(pipex.cmd1, args[2], envp);
  }
}
/**
 * @brief This function handles the end part of the pipe where the second command happens
 * @param pipex The struct where evrythig is stored
 * @param args The arguments given in the terminal 
 * @param envp The enviroment variables array
*/
void  second_child(t_pipex pipex, char **args, char **envp)
{
  pipex.pid2 = fork();
  if (pipex.pid2 < 0)
    return ;
  if (pipex.pid2 == 0)
  {
    dup2(pipex.fd[0], STDIN_FILENO);
    close(pipex.fd[1]);  
    dup2(pipex.outfile, 1);
    close(pipex.fd[0]);
    execve(pipex.cmd2, args[3], envp);
  }
}



