/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyou <juyou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 17:29:15 by tsecret           #+#    #+#             */
/*   Updated: 2021/06/10 00:21:31 by juyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	func_if(va_list ptr, const char **format)
{
	struct s_flags flag;

	flag = parse_flags(&(*format), ptr);
	if (**format == 'c')
		return (ft_print_c(va_arg(ptr, int), flag));
	else if (**format == 's')
		return (ft_str(va_arg(ptr, char*), flag));
	else if (**format == 'd' || **format == 'i')
		return (ft_itoa(va_arg(ptr, int), flag));
	else if (**format == '%')
		return (ft_print_c('%', flag));
	else if (**format == 'p')
		return (ft_pointer(va_arg(ptr, unsigned long int), flag));
	// else if (**format == 'u')
	// 	return (ft_hex(ptr, 10, 0, flag));
	// else if (**format == 'x')
	// 	return (ft_hex(ptr, 16, 0, flag));
	// else if (**format == 'X')
	// 	return (ft_hex(ptr, 16, 1, flag));
	else
		return (print_char(**format));
}

static	int	find_pct(va_list ptr, const char **format)
{
	int i;

	i = 0;
	while (**format)
	{
		if (**format == '%')
			i += func_if(ptr, &(*format));
		else
			i += print_char(**format);
		(*format)++;
	}
	return (i);
}

int			ft_printf(const char *format, ...)
{
	va_list	ptr;
	int		n;

	n = 0;
	va_start(ptr, format);
	n = find_pct(ptr, &format);
	va_end(ptr);
	return (n);
}
