#include "../inc/pipex.h"
#include "../srcs/libft/libft.h"


void  free_childs(t_pipex *pipex)
{
  int i;

  i = 0;
  while (pipex->cmd_args[i])
  {
    free(pipex->cmd_args[i]);
    i++;
  }
  free(pipex->cmd_args);
  free(pipex->cmd);
}
/**
 * @brief This function handles the beggining part of the pipe where the first command happens
 * @param pipex The struct where evrythig is stored
 * @param args The arguments given in the terminal 
 * @param envp The enviroment variables array
*/
void  first_child(t_pipex pipex, char **args, char**envp)
{
  dup2(pipex.fd[1], STDOUT_FILENO);
  close(pipex.fd[0]);   
  dup2(pipex.infile, 0);
  close(pipex.fd[1]);
  pipex.cmd_args = ft_split(args[2], ' ');
  pipex.cmd = ft_get_cmd(pipex.parse_paths, pipex.cmd_args[0]);
  if (!pipex.cmd)
  {
    free_childs(&pipex);
    error_msg("Error_Cmd");
    exit(1);
  }
  printf("\n First Child \nPipex.cmd = %s\nPipex.cmd_args[0] = %s\nPipex.cmd_args[1] = %s\n", pipex.cmd, pipex.cmd_args[0], pipex.cmd_args[1]);
  execve(pipex.cmd, pipex.cmd_args, envp);
}
/**
 * @brief This function handles the end part of the pipe where the second command happens
 * @param pipex The struct where evrythig is stored
 * @param args The arguments given in the terminal 
 * @param envp The enviroment variables array
*/
void  second_child(t_pipex pipex, char **args, char **envp)
{
  dup2(pipex.fd[0], STDIN_FILENO);
  close(pipex.fd[1]);  
  dup2(pipex.outfile, 1);
  close(pipex.fd[0]);
  pipex.cmd_args = ft_split(args[2], ' ');
  pipex.cmd = ft_get_cmd(pipex.parse_paths, pipex.cmd_args[0]);
  if (!pipex.cmd)
  {
    free_childs(&pipex);
    error_msg("Error_Cmd");
    exit(1);
  }
  printf("\n Second Child \nPipex.cmd = %s\nPipex.cmd_args[0] = %s\nPipex.cmd_args[1] = %s\n", pipex.cmd, pipex.cmd_args[0], pipex.cmd_args[1]);
  execve(pipex.cmd, pipex.cmd_args, envp);
}



