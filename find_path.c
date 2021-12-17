#include "pipex.h"

char *find_path(char **envp, char *path_name)
{
	char	**paths;
	int		i;
	int		count;
	char	*find_path;
	char	*try_path;

	count = 0;
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			paths = ft_split(envp[i] + 5, ':');
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
		}
		i++;
	}
	return (NULL);
}
