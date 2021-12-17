#ifndef PIPEX_H
# define PIPEX_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "Libft/libft.h"

# define SUCCES 1
# define ERROR 0
typedef struct  t_argv
    {
       char *cmd1;
	   char **path1;
	   char	*cmd2;
	   char **path2;
	   char *file_in;
	   int	i_file_in;
	   char *file_out;
	   int	i_file_out;
	   char **envp;
	   int fd[2];
	   int pid;
    }t_argv;

int main(int argc, char **argv, char **envp);
char  *find_path (char **envp, char *path_name);
void childeren(t_argv *data);
void parent(t_argv *data);
void my_fork(t_argv *data);
char	**add_path(char **path, int len, char **envp);
int how_many(char **path);
#endif
