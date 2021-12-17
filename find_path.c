#include "pipex.h"

char	*try_path(char **paths, char *path_name)
{
	char	*find_path;
	char	*try_path;
	int		count;

	count = 0;
	while (paths[count])
	{
		try_path = ft_strjoin(paths[count], "/");
		find_path = ft_strjoin(try_path, path_name);
		if (access(find_path, X_OK) == 0)
		{
			free(try_path);
			return (find_path);
		}
		else
		{
			free(try_path);
			free(find_path);
		}
		count++;
	}
	return (NULL);
}

char	*find_path(char **envp, char *path_name)
{
	char	**paths;
	int		i;
	int		count;
	char	*find_path;

	count = 0;
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			paths = ft_split(envp[i] + 5, ':');
			find_path = try_path(paths, path_name);
			return (find_path);
		}
		i++;
	}
	return (NULL);
}
