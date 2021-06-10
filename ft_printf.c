/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyou <juyou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:26:08 by juyou             #+#    #+#             */
/*   Updated: 2021/06/10 14:32:32 by juyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_type(va_list ap, const char **format)
{
	struct s_flags flags;

	flags = parse_flag(&(*format), ap);
	if (**format == 'c')
		return (ft_print_c(va_arg(ap, int), flags));
	else if (**format == 's')
		return (ft_printf_str(va_arg(ap, char*), flags));
	else if (**format == 'd' || **format == 'i')
		return (ft_itoa(va_arg(ap, int), flags));
	else if (**format == '%')
		return (ft_print_c('%', flags));
	else if (**format == 'p')
		return (ft_pointer(va_arg(ap, unsigned long int), flags));
	else if (**format == 'u')
		return (ft_uint(ap, 10, 0, flags));
	else if (**format == 'x')
		return (ft_uint(ap, 16, 0, flags));
	else if (**format == 'X')
		return (ft_uint(ap, 16, 1, flags));
	else
		return (print_char(**format));
}

static int	ft_parse(va_list ap, const char **format)
{
	int size;

	size = 0;
	while (**format)
	{
		if (**format != '%')
			size += print_char(**format);
		else
			size += ft_type(ap, &(*format));
		(*format)++;
	}
	return (size);
}

int			ft_printf(const char *format, ...)
{
	va_list ap;
	int		size;

	size = 0;
	va_start(ap, format);
	size = ft_parse(ap, &format);
	va_end(ap);
	return (size);
}
