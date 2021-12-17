/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   childeren.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 12:43:13 by adoner        #+#    #+#                 */
/*   Updated: 2021/12/16 16:09:44 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	childeren(t_argv *data)
{
	int	len;

	data->i_file_in = open(data->file_in, O_RDONLY);
	if (data->i_file_in == -1)
		exit(1);
	dup2(data->i_file_in, 0);
	dup2(data->fd[1], 1);
	close(data->fd[0]);
	close(data->fd[1]);
	data->path1 = ft_split(data->cmd1, ' ');
	len = how_many(data->path1);
	data->path1 = add_path(data->path1, len, data->envp);
	close(data->fd[1]);
	close(data->fd[0]);
	execve(data->path1[0], data->path1, data->envp);
	perror("Error with execve");
}
