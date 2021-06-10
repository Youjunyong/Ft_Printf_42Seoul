/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyou <juyou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:01:58 by juyou             #+#    #+#             */
/*   Updated: 2021/06/10 14:00:23 by juyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_num(char **str)
{
	int size;

	size = 0;
	if (*str[0] == '-')
		size += print_char(*str[0]);
	if ((*str)[0] == '0' && (*str)[1] == 'x')
		size += print_str("0x", 2);
	(*str) += size;
	return (size);
}

int		ft_printf_int(char *str, struct s_flags flags)
{
	int	len;

	if (str[0] == '0' && !flags.precision && flags.dot)
		str[0] = '\0';
	flags.str_len = ft_strlen(str);
	if (flags.precision && flags.precision > flags.str_len && !flags.width)
		len = flags.precision - flags.str_len;
	else if (flags.precision && flags.width && flags.precision > flags.str_len)
		len = flags.width - flags.precision;
	else
		len = flags.width - flags.str_len;
	if (str[0] == '-' && flags.precision >= flags.str_len)
		len--;
	if (flags.width && (!flags.zero || flags.dot) && !flags.minus)
		flags.size += ft_align(' ', len);
	if (flags.zero && !flags.minus && !flags.dot)
		flags.size += check_num(&str) + ft_align('0', len);
	if (flags.precision >= flags.str_len && flags.dot)
		flags.size += check_num(&str) + ft_align('0',
		flags.precision - ft_strlen(str));
	flags.size += print_str(str, ft_strlen(str));
	if (flags.width && flags.minus)
		flags.size += ft_align(' ', len);
	return (flags.size);
}
