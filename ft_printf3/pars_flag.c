/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyou <juyou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 20:43:09 by tsecret           #+#    #+#             */
/*   Updated: 2021/06/08 16:04:58 by juyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"




struct s_flags	ft_flags(void)
{
	struct s_flags flag;

	flag.minus = 0;
	flag.count = 0;
	flag.zero = 0;
	flag.dot = 0;
	flag.width = 0;
	flag.precision = 0;
	flag.sign_w = 0;
	flag.len_list = 0;
	return (flag);
}

int	spec(int c)
{
	const char *str = TYPE;
	while (*str != (char)c)
		if (!*str++)
			return (1);
	return (0);
}

struct s_flags	parse_flags(const char **format, va_list ptr)
{
	struct s_flags flag;

	flag = ft_flags();
	(*format)++;
	while (**format && spec(**format))
	{
		if (**format == '-')
			flag.minus = 1;
		else if (**format == '0' && !flag.minus)
			flag.zero = 1;
		else if (**format == '.' && !flag.dot)
			flag.precision = ft_precision(&(*format), ptr, &flag);
		else if (ft_isdigit(**format) || **format == '*')
			flag.width = ft_width(&(*format), ptr, &flag);
		else
			break ;
		(*format)++;
	}
	return (flag);
}
