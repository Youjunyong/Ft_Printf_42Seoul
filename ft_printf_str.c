/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyou <juyou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 15:02:47 by juyou             #+#    #+#             */
/*   Updated: 2021/06/10 14:58:34 by juyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_str(char *str, int len)
{
	if (len == 0)
		return (0);
	return (write(1, str, len));
}

int		ft_printf_str(char *str, struct s_flags flags)
{
	int	len;

	if (str == NULL)
		str = "(null)";
	flags.str_len = ft_strlen(str);
	if (flags.precision && flags.precision > flags.str_len)
		flags.precision = flags.str_len;
	if (flags.dot && flags.precision < flags.str_len)
		(len = flags.width - flags.precision);
	else
		len = flags.width - flags.str_len;
	if (!flags.minus && !flags.zero && flags.width > 0)
		flags.size += ft_align(' ', len);
	if (flags.zero && !flags.minus)
		flags.size += ft_align('0', len);
	if (flags.dot)
		(flags.size += print_str(str, flags.precision));
	else
		(flags.size += print_str(str, flags.str_len));
	if (flags.minus)
		flags.size += ft_align(' ', len);
	return (flags.size);
}
