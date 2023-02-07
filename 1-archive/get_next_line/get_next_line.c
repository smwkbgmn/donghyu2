/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:15:11 by donghyu2          #+#    #+#             */
/*   Updated: 2023/02/07 10:43:37 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_list			*node;
	char			*line;

	line = NULL;
	if (fd != ERROR && BUFFER_SIZE > 0)
	{
		node = init_node(&head, fd);
		if (node)
		{
			if (!node->str)
			{
				node->str = get_str(fd, 0);
				node->ptr = node->str;
			}
			line = read_line(node, fd);
			if (!line || !node->str)
				del_node(&head, fd);
		}
	}
	return (line);
}

char	*read_line(t_list *node, int fd)
{
	char	*line;
	char	*new;
	char	*nl;

	line = NULL;
	if (node->str && *node->str)
	{
		new = NULL;
		nl = ft_strchr(node->ptr, '\n');
		if (!nl)
			new = get_str(fd, 0);
		if (nl || new)
		{
			line = ft_strjoin(node->ptr, new);
			adjust_node(node, new);
		}
	}
	return (line);
}

char	*get_str(int fd, size_t len_total)
{
	char	*buf;
	char	*str;
	ssize_t	len;

	str = NULL;
	buf = malloc(BUFFER_SIZE + 1);
	if (buf)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len != ERROR)
		{
			buf[len] = '\0';
			if (len > 0 && !ft_strchr(buf, '\n'))
				str = get_str(fd, len_total + len);
			else
			{
				str = malloc(len_total + len + 1);
				if (str)
					str[len_total + len] = '\0';
			}
			ft_memcpy(str + len_total, buf, len * (str != NULL));
		}
		free(buf);
	}
	return (str);
}

t_list	*init_node(t_list **head, int fd)
{
	t_list	*node;
	t_list	*new;

	node = *head;
	if (node)
	{
		while (node->fd != fd && node->next)
			node = node->next;
		if (node->fd == fd)
			return (node);
	}
	new = malloc(sizeof(t_list));
	if (new)
	{
		new->fd = fd;
		new->str = NULL;
		new->next = NULL;
		if (!node)
			*head = new;
		else
			node->next = new;
	}
	return (new);
}

void	del_node(t_list **head, int fd)
{
	t_list	*node;
	t_list	*del;

	node = *head;
	if (node->fd == fd)
	{
		del = node;
		*head = node->next;
	}
	else
	{
		while (node->next->fd != fd)
			node = node->next;
		del = node->next;
		node->next = del->next;
	}
	if (del->str)
		free(del->str);
	free(del);
}
