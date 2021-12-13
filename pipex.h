#ifndef PIPEX_H
# define PIPEX_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#include "Libft/libft.h"
int main(int argc, char **argv, char **envp);
char  *find_path (char **envp, char *path_name);
void first_fork(int pid,char **argv, int fd[2], char **envp);
void second_fork(int pid, char **argv, int fd[2], char **envp);
char	**add_path(char **path, int len, char **envp);
int how_many(char **path);
#endif
