/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spcf_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:54:11 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/26 05:51:46 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"
#include "libft.h"

char	*spcf_p(va_list *ptr)
{
	char	*dec;
	char	*hex;
	char	*address;

	address = 0;
	dec = ft_itoa_long(va_arg(*ptr, unsigned long));
	if (dec)
	{
		hex = ft_convert_base(dec, "0123456789", "0123456789abcdef");
		if (hex)
		{
			address = ft_strjoin("0x", hex);
			free(hex);
		}
		free(dec);
	}
	return (address);
}