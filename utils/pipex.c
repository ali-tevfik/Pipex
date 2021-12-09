/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/25 13:38:20 by adoner        #+#    #+#                 */
/*   Updated: 2021/12/05 01:02:17 by tevfik        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	if (argc != 4)
		return(0);

	int fd[2];
	int id;

	argv[1];

	if (pipe(fd) == -1)
		return (0);

	id = fork();
	if (id == -1)
		return (0);
	if (id == 0)
	{
		//childeren

	}
	return (0);
}
