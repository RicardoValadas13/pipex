#include "../inc/pipex.h"

//ft_check_args 
#include <unistd.h>
#include <fcntl.h>
char*  ft_store_path(char **envp)
{
  while (envp != NULL && ft_strncmp("PATH", *envp, 4))
    envp++;
  retunr(*envp + 5);
}
void  ft_check_args(char **args, char **envp)
{
  t_pipex pipex;
  
  pipex.infile = open(args[1], O_RDONLY);
  if(pipex.infile < 0)
    return (1);
  pipex.outfile = open(args[4],O_CREAT , O_WRONLY);
  if(pipex.outfile < 0)
    return (2);
  if(pipe(pipex.fd) < 0)
    return (3);
  pipex.path = ft_store_path(envp);   
  
      
  write();
}
