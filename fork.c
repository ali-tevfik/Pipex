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

void my_fork(t_argv *data)
{
	int		len;

	if (data->pid == 0)
    {
		data->i_file_in = open(data->file_in,O_RDONLY);
		dup2(data->i_file_in,0);
        dup2(data->fd[1],1);
        close(data->fd[0]);
        close(data->fd[1]);
		data->path1 = ft_split(data->cmd1,' ');
		for(int i = 0; data->path1[i];i++)
			printf("data1 = %s\n",data->path1[i]);
		len = how_many(data->path1);
		data->path1 = add_path(data->path1, len, data->envp);

		for(int i = 0; data->path1[i];i++)
			printf("data2 = %s\n",data->path1[i]);
    	close(data->fd[1]);
    	close(data->fd[0]);
    	execve(data->path1[0],data->path1,data->envp);
    	perror("Error with execve");
    }
    else
    {
		data->i_file_out = open(data->file_out, O_WRONLY | O_TRUNC | O_CREAT, 0777);
		dup2(data->fd[0],0);
		dup2(data->i_file_out, 1);
		close(data->fd[1]);
		close (data->fd[0]);
		close(data->i_file_out);
		data->path2 = ft_split(data->cmd2, ' ');
		int len2 = how_many(data->path2);
		data->path2 = add_path(data->path2, len2, data->envp);
		execve(data->path2[0],data->path2,data->envp);
        perror("Error with execve");

    }
}
