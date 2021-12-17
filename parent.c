/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parent.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 12:44:47 by adoner        #+#    #+#                 */
/*   Updated: 2021/12/17 19:05:27 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent(t_argv *data)
{
	int	len;

	waitpid(data->pid, NULL, 0);
	data->i_file_out = open(data->file_out, O_WRONLY | O_TRUNC | O_CREAT, 0666);
	if (data->i_file_out == -1)
		exit(ERROR);
	dup2(data->fd[0], 0);
	dup2(data->i_file_out, 1);
	close(data->fd[1]);
	close (data->fd[0]);
	close(data->i_file_out);
	data->path2 = ft_split(data->cmd2, ' ');
	len = how_many(data->path2);
	data->path2 = add_path(data->path2, len, data->envp);
	execve(data->path2[0], data->path2, data->envp);
	perror("Error with execve");
	exit(ERROR2);
}
