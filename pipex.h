#ifndef PIPEX_H
# define PIPEX_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "Libft/libft.h"
int main(int argc, char **argv, char **envp);
char  *find_path (char **envp, char *path_name);
#endif
