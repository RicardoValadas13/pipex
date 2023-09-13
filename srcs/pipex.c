#include "../inc/pipex.h"

int main(int ac,char **av, char **envp)
{
    if (ac == 5)
    {
        ft_init_pipex();
        ft_check_args(av, envp);
        ft_parse_cmds();
        ft_parse_args();
        while (cmds)
            ft_exec();
        ft_cleanup();
    }
    return (err);
}

