/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_x_lower.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:54:24 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/04 17:38:46 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

#include <stdlib.h>

short	type_x_lower(va_list *ptr, t_list *head)
{
	char	*dec;
	char	*hex;

	dec = ft_itoa_ul(va_arg(*ptr, unsigned int));
	if (dec)
	{
		hex = ft_convert_base_ul(dec, "0123456789", "0123456789abcdef");
		ft_lstidx(head, 3)->content = hex;
		free(dec);
		return (SUCCESS);
	}
	else
		return (ERROR);
}
