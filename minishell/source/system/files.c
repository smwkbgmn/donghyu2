/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 15:43:12 by donghyu2          #+#    #+#             */
/*   Updated: 2023/09/10 15:44:21 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#include "minishell.h"

int	open_fd(char *name, int option, int permit, int flag)
{
	int	fd;

	if (!permit)
		fd = open(name, option);
	else
		fd = open(name, option, permit);
	if (fd == ERROR && flag > -1)
	{
		if (flag == R)
			perror("open");
		else
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
	if (fd_to_copy != ERROR)
	{
		if (dup2(fd_to_copy, fd_to_be) == ERROR)
			exit_with_error("dup2");
	}
}

