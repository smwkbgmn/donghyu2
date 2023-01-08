/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:23:55 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/08 23:06:48 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		get_width(char *format, t_list *head);
static size_t	get_len_full_str(t_list *head, short type);

short	flag_width(char *format, t_list *head)
{
	char	*spaces;
	int		width;

	width = get_width(format, head);
	if (width > 0)
	{
		spaces = get_str_fill_char(width, ' ');
		if (spaces)
			ft_lstidx(head, 0)->content = spaces;
		else
			return (FALSE);
	}
	return (TRUE);
}

static int	get_width(char *format, t_list *head)
{
	format += pass_flag(format);
	return (ft_atoi(format) - get_len_full_str(head, get_type_str(format)));
}

static size_t	get_len_full_str(t_list *head, short type)
{
	size_t	len;

	len = 0;
	while (head)
	{
		if (head->content)
		{
			if (type_c_with_null(type, head->content))
				len += 1;
			else
				len += ft_strlen(head->content);
		}
		head = head->next;
	}
	return (len);
}
