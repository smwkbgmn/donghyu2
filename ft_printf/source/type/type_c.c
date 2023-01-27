/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:09:29 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/27 13:39:37 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

short	type_c(va_list *ptr, t_list	*head)
{
	char	*content;

	content = ft_calloc(2, 1);
	if (content)
	{
		content[0] = va_arg(*ptr, int);
		ft_lstidx(head, 3)->content = content;
		return (TRUE);
	}
	else
		return (FALSE);
}
