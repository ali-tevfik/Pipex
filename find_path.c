#include "pipex.h"

char *find_path (char **envp, char *path_name)
{
	char **a;
	for (size_t i = 0; envp[i] ; i++)
	{
		 if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			// printf("envp = %s\n",envp[i]);
			a = ft_split(envp[i] + 5, ':');
			for (size_t b = 0; b[a]; b++)
			{
				 char *c = ft_strjoin(b[a],"/");
				 char *deneme = ft_strjoin(c,path_name);
				 if (access(deneme, X_OK) == 0)
				 	return(deneme);
			}


        }
	}
	return (NULL);
}
