/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 12:46:50 by adoner        #+#    #+#                 */
/*   Updated: 2021/12/17 19:08:38 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		i;
	t_argv	data;

	if (argc == 4)
		exit(ERROR);
	data.cmd1 = argv[2];
	data.cmd2 = argv[3];
	data.file_in = argv[1];
	data.file_out = argv[4];
	data.envp = envp;
	if (pipe(data.fd) == -1)
		error_text("Pipe Error");
	data.pid = fork();
	if (data.pid == -1)
		error_text("Fork Error");
	my_fork(&data);
	return (SUCCES);
}

//hata 1 yoksa 0
