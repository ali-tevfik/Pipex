#include "pipex.h"

typedef struct  t_deneme
    {
       char *data[4];
    }s_deneme;

int main(int argc, char **argv, char **envp)
{
    char **path;
    path = ft_split(argv[2],' ');
    char *which_path = find_path(envp, path[0]);
    char *deneme[3] = {which_path,path[1],NULL};

    int fd[2];
    int i ;

    i = argc;
    pipe(fd);
    int pid = fork();

    if (pid == 0)
    {
        dup2(fd[1],1);
        close(fd[1]);
        close(fd[0]);

        execve(deneme[0],deneme,NULL);

    }
    else
    {
        dup2(fd[0],0);
        close(fd[0]);
        close(fd[1]);
        char **path2 = ft_split(argv[3],' ');
        char *which_part_2 = find_path(envp,path2[0]);
        char *a[3] = {which_part_2,path2[1],NULL};

        execve(a[0],a,NULL);

    }

    waitpid(pid,NULL,0);

}
