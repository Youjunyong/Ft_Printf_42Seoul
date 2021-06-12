/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyou <juyou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:00:41 by juyou             #+#    #+#             */
/*   Updated: 2021/06/10 12:00:13 by juyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_width(const char **format, va_list ap, struct s_flags *flag)
{
	int width;

	width = 0;
	if (**format == '*')
	{
		width = va_arg(ap, int);
		// width에 음수가 할당되면 -(왼쪽정렬) + width로 간주된다.
		if (width < 0) 
		{
			flag->minus = 1;
			width *= -1;
		}
	}
	else if (ft_isdigit(**format))
	{
		width = ft_atoi(*format);
		while (ft_isdigit(*(*format + 1)))
			(*format)++;
	}
	return (width);
}