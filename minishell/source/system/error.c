/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:21:33 by donghyu2          #+#    #+#             */
/*   Updated: 2023/09/19 16:35:44 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "minishell.h"

void	*errex(void *ptr)
{
	if (!ptr)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	return (ptr);
}

void	exit_with_error(char *msg)
{
	if (msg)
		perror(msg);
	/* NEED TO DECLARE THE EXIT CODES */
	exit(EXIT_FAILURE);
}
