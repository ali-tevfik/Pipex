/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 12:46:50 by adoner        #+#    #+#                 */
/*   Updated: 2021/12/17 18:50:30 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		i;
	t_argv	data;

	if (argc == 4)
		exit(1);
	data.cmd1 = ft_strdup(argv[2]);
	data.cmd2 = argv[3];
	data.file_in = argv[1];
	data.file_out = argv[4];
	data.envp = envp;
	pipe(data.fd);
	data.pid = fork();
	my_fork(&data);
	waitpid(data.pid, NULL, 0);
	return (0);
}

//hata 1 yoksa 0
