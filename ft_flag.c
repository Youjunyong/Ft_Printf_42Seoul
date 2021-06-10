/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyou <juyou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:47:13 by juyou             #+#    #+#             */
/*   Updated: 2021/06/10 14:16:46 by juyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

struct	s_flags	ft_flag_init(void)
{
	struct s_flags flags;

	flags.minus = 0;
	flags.size = 0;
	flags.zero = 0;
	flags.dot = 0;
	flags.width = 0;
	flags.precision = 0;
	flags.sign_w = 0;
	flags.str_len = 0;
	return (flags);
}

static int		custom_strchr(int c)
{
	const char *str = TYPE;

	while (*str != (char)c)
		if (!*str++)
			return (1);
	return (0);
}

struct	s_flags	parse_flag(const char **format, va_list ap)
{
	struct s_flags flags;

	flags = ft_flag_init();
	(*format)++;
	while (**format && custom_strchr(**format))
	{
		if (**format == '-')
			flags.minus = 1;
		else if (**format == '0' && !flags.minus)
			flags.zero = 1;
		else if (**format == '.' && !flags.dot)
			flags.precision = ft_prec(&(*format), ap, &flags);
		else if (ft_isdigit(**format) || **format == '*')
			flags.width = ft_width(&(*format), ap, &flags);
		else
			break ;
		(*format)++;
	}
	return (flags);
}
