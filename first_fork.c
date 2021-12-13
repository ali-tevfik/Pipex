#include "pipex.h"

int how_many(char **path)
{
	int	i;

	i = 0;
	while(path[i])
		i++;
	return(i);
}

char	**add_path(char **path, int len, char **envp)
{
	char	**new_path;
	int		i;
	char	*which_path;

	which_path = find_path(envp, path[0]);
    	if (which_path == NULL)
    		which_path = path[0];
	new_path = (char **)malloc(sizeof(new_path) * (len + 1));
	if (!new_path)
		exit(0);
	new_path[0] = which_path;
	i = 1;
	while (path[i])
	{
		new_path[i] = path[i];
		i++;
	}
	new_path[i] = NULL;
	free(path);
	return(new_path);
}

void first_fork(int pid,char **argv, int fd[2], char **envp)
{
	char	**path;
	int		len;
	int		pid2;

	if (pid == 0)
    {
		int file_in = open(argv[1],O_RDONLY);
		dup2(file_in,0);
        dup2(fd[1],1);
        close(fd[0]);
        close(fd[1]);
		path = ft_split(argv[2],' ');
		len = how_many(path);
		path = add_path(path, len, envp);
    	dup2(fd[1],1);
    	close(fd[1]);
    	close(fd[0]);
    	execve(path[0],path,envp);
    	perror("Error with execve");
    }
    else
    {
		int file_out = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0777);
		dup2(fd[0],0);
		dup2(file_out, 1);
		close(fd[1]);
		close (fd[0]);
		close(file_out);
		char **path2 = ft_split(argv[3],' ');
        char *which_part_2 = find_path(envp,path2[0]);
        if (which_part_2 == NULL)
            which_part_2 = path2[0];
        char *a[3] = {which_part_2,path2[1],NULL};
        execve(a[0],a,NULL);
        perror("Error with execve");

    }
}
