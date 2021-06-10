/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpotter <wpotter@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 23:24:35 by tsecret           #+#    #+#             */
/*   Updated: 2020/07/28 01:36:50 by wpotter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_hex(va_list ptr, int buf, int flag, struct s_flags flags)
{
	char *list;

	list = ft_utoa(va_arg(ptr, unsigned int), buf, flag);
	flags.len_list = ft_strlen(list);
	if (flags.precision == 0 && flags.dot && list[0] == '0')
		flags.len_list--;
	if (flags.width && !flags.minus && !flags.dot && !flags.zero)
		flags.count += ft_align(' ', flags.width - flags.len_list);
	else if (flags.width && (flags.dot || !flags.zero) && !flags.minus)
		flags.count += ft_align(' ', flags.precision >= flags.len_list
		? flags.width - flags.precision : flags.width - flags.len_list);
	if (flags.zero && !flags.minus && flags.width && !flags.dot)
		flags.count += ft_align('0', flags.width - flags.len_list);
	if (flags.dot)
		flags.count += ft_align('0', flags.precision - flags.len_list);
	flags.count += print_str(list, flags.len_list);
	if (flags.minus)
		flags.count += ft_align(' ', flags.precision >= flags.len_list
		? flags.width - flags.precision : flags.width - flags.len_list);
	free(list);
	return (flags.count);
}
