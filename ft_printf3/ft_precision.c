/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyou <juyou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 17:31:13 by tsecret           #+#    #+#             */
/*   Updated: 2021/06/08 16:48:37 by juyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_precision(const char **format, va_list ptr, struct s_flags *flag)
{
	int precision;

	precision = 0;
	flag->dot = 1;
	if (*(*format + 1) == '*')
	{
		(*format)++;
		precision = va_arg(ptr, int);
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
