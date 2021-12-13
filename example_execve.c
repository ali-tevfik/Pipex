#include "pipex.h"


int main(int argc, char **argv, char **envp)
{
    int i ;
	t_argv data;

	if (argc == 4)
		exit(777);
	if (access(argv[1], F_OK) != 0)
		return(-1);
	data.cmd1 = ft_strdup(argv[2]);
	data.cmd2 = argv[3];
	data.file_in = argv[1];
	data.file_out = argv[4];
	data.envp = envp;
	pipe(data.fd);
    data.pid = fork();
	my_fork(&data);
    waitpid( data.pid, NULL, 0);
	return(127);
}
