/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpotter <wpotter@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 00:30:36 by tsecret           #+#    #+#             */
/*   Updated: 2020/07/28 01:51:24 by wpotter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_width(const char **format, va_list ptr, struct s_flags *flag)
{
	int width;

	width = 0;
	if (**format == '*')
	{
		width = va_arg(ptr, int);
		if (width < 0)
		{
			flag->minus = 1;
			width = -width;
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
