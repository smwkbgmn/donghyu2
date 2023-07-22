/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:58:56 by donghyu2          #+#    #+#             */
/*   Updated: 2023/07/22 15:42:33 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#include "pipex.h"

int	open_fd(char *name, int option, int permit, int flag)
{
	int	fd;

	if (!permit)
		fd = open(name, option);
	else
		fd = open(name, option, permit);
	if (fd == ERROR)
	{
		perror("open");
		if (flag == R)
			fd = STDIN_FILENO;
		else if (flag == W)
			exit_with_error("open");
	}
	return (fd);
}

void	close_fd(int fd)
{
	if (close(fd) == ERROR)
		exit_with_error("close");
}

void	redirect(int fd_to_copy, int fd_to_be)
{
	if (dup2(fd_to_copy, fd_to_be) == ERROR)
		exit_with_error("dup2");
}
