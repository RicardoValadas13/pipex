#include "../inc/pipex.h"
#include "../srcs/libft/libft.h"

char*  ft_store_path(char **envp)
{
  while (envp)
  {
    if (!ft_strncmp("PATH=", *envp, 5))
      return(*envp + 5);
    envp++;
  }
  return (NULL);
}

char*  ft_parse_args(char **paths, char *args)
{
  char *tmp;
  char *tmp1;
  while (*paths)
  {
    tmp = ft_strjoin(*paths, "/");
    tmp1 = ft_strjoin(tmp, args);
    free(tmp);
    if (!access(tmp1, X_OK | F_OK))    
      return (tmp1); 
    free(tmp1);
    paths++;
  }
  return (NULL) ;
}
void  ft_check_args(char **args, char **envp)
{
  t_pipex pipex;
  int i;
  i = 0;

 /*  pipex.infile = open(args[1], O_RDONLY);
  if (pipex.infile < 0)
    return ;
  pipex.outfile = open(args[4],O_CREAT , O_WRONLY);
  if (pipex.outfile < 0)
    return ;
  if(pipe(pipex.fd) < 0)
    return ; */

  pipex.path = ft_store_path(envp); 
  pipex.parse_paths = ft_split(pipex.path, ':');
  pipex.parse_args = ft_parse_args(pipex.parse_paths, args[2]); 
  pipex.parse_args = ft_parse_args(pipex.parse_paths, args[3]);
  
  printf("%s", pipex.parse_args[0]);
  while(pipex.parse_args[i])
    free (pipex.parse_args[i++]);  
  free(pipex.parse_args);
  i = 0; 
  while(pipex.parse_paths[i])
    free (pipex.parse_paths[i++]);  
  free(pipex.parse_paths);
}
