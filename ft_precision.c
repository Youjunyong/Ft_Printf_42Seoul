/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyou <juyou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 16:40:11 by juyou             #+#    #+#             */
/*   Updated: 2021/06/10 12:04:57 by juyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_precision(const char **format, va_list ap, struct s_flags *flag)
{
	int precision;

	precision = 0;
	flag->dot = 1;
	if (*(*format + 1) == '*')
	{
		(*format)++;
		precision = va_arg(ap, int);
		if (precision < 0)
			flag->dot = 0;
	}
	else if (ft_isdigit(*(*format + 1)))
	{
		(*format)++;
		precision = ft_atoi(*format);
		while (ft_isdigit(*(*format + 1)))
			(*format)++;
	}
	return (precision);

}