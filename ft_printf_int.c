/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyou <juyou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:01:58 by juyou             #+#    #+#             */
/*   Updated: 2021/06/10 12:05:36 by juyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int							check_num(char **str)
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

int ft_printf_int(char *str, struct s_flags flag)
{
	int len;

	if (str[0] == '0' && !flag.precision && flag.dot)
		str[0] = '\0';
	flag.str_len = ft_strlen(str);
	if (flag.precision && flag.precision > flag.str_len && !flag.width)
		len = flag.precision - flag.str_len;
	else if (flag.precision && flag.width && flag.precision > flag.str_len)
		len = flag.width - flag.precision;
	else
		len = flag.width - flag.str_len;
	if (str[0] == '-' && flag.precision >= flag.str_len)
		len--;
	if (flag.width && (!flag.zero || flag.dot) && !flag.minus)
		flag.size += ft_align(' ', len);
	if (flag.zero && !flag.minus && !flag.dot)
		flag.size += check_num(&str) + ft_align('0', len);
	if (flag.precision >= flag.str_len && flag.dot)
		flag.size += check_num(&str) + ft_align('0',
		flag.precision - ft_strlen(str));
	flag.size += print_str(str, ft_strlen(str));
	if (flag.width && flag.minus)
		flag.size += ft_align(' ', len);
	return (flag.size);
}