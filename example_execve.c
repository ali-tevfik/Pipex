#include "pipex.h"

typedef struct  t_deneme
    {
       char *data[4];
    }s_deneme;

int main(int argc, char **argv, char **envp)
{


    int fd[2];
    int i ;


    i = argc;
    pipe(fd);
    int pid = fork();
	first_fork(pid,argv, fd,envp);
    waitpid(pid,NULL,0);

}
