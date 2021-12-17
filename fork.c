/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fork.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 12:45:56 by adoner        #+#    #+#                 */
/*   Updated: 2021/12/17 16:49:38 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	how_many(char **path)
{
	int	i;

	i = 0;
	while (path[i])
		i++;
	return (i);
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
		exit(ERROR);
	new_path[0] = which_path;
	i = 1;
	while (path[i])
	{
		new_path[i] = path[i];
		i++;
	}
	new_path[i] = NULL;
	free(path);
	return (new_path);
}

void	my_fork(t_argv *data)
{
	int		len;

	if (data->pid == 0)
		childeren(data);
	else
		parent(data);
}
