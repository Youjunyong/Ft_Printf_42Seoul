/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyou <juyou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:47:13 by juyou             #+#    #+#             */
/*   Updated: 2021/06/10 12:04:49 by juyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



struct s_flags ft_flag_init(void)
{
	struct s_flags flag;

	flag.minus = 0;
	flag.size = 0;
	flag.zero = 0;
	flag.dot = 0;
	flag.width = 0;
	flag.precision = 0;
	flag.sign_w = 0;
	flag.str_len = 0;
	return (flag);
}

static int	custom_strchr(int c)
{
	const char *str = TYPE;
	
	while (*str != (char)c)
		if (!*str++)
			return (1);
	return (0);
}


struct s_flags	parse_flag(const char **format, va_list ap)
{
	struct s_flags flag;
	flag = ft_flag_init();

	(*format)++;
	while (**format && custom_strchr(**format))
	{
		if(**format == '-')
			flag.minus = 1;
		else if (**format == '0' && !flag.minus)
			flag.zero = 1;


		else if (**format == '.' && !flag.dot)
			flag.precision = ft_precision(&(*format), ap, &flag);
		else if (ft_isdigit(**format) || **format == '*')
			flag.width = ft_width(&(*format), ap, &flag);
		else
			break;
		(*format)++;
	}
	return (flag);
}
