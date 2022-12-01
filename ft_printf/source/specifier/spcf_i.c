/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spcf_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:54:03 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/02 01:42:35 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

size_t	spcf_i(va_list *ptr)
{
	return (ft_putnbr_len(va_arg(*ptr, int), 0));
}