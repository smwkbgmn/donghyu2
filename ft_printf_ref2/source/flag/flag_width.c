/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:23:55 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/04 12:33:47 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static size_t	get_len_full_str(t_list *head);

void	flag_width(const char *str, t_list **head)
{
	t_list	*node_new;
	char	*spaces;
	int		width;

	str += pass_flag(str);
	width = ft_atoi(str) - get_len_full_str(*head);
	if (width > 0)
	{
		spaces = get_str_fill_char(width, ' ');
		if (spaces)
		{
			node_new = ft_lstnew(spaces);
			if (node_new)
				ft_lstadd_front(head, node_new);
		}
	}
}

static size_t	get_len_full_str(t_list *head)
{
	size_t	len;

	len = 0;
	while (head)
	{
		len += ft_strlen(head->content);
		head = head->next;
	}
	return (len);
}
