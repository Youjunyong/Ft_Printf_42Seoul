/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyou <juyou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:10:34 by juyou             #+#    #+#             */
/*   Updated: 2021/06/10 12:05:14 by juyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	print_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_align(int c, int len)
{
	int size;

	size = 0;
	while (len > 0)
	{
		size += print_char(c);
		len--;
	}
	return (size);
}

int	ft_print_c(char c, struct s_flags flag)
{
	if (flag.width && !flag.zero && !flag.minus)
		flag.size += ft_align(' ', flag.width - 1);
	else if (flag.zero && !flag.minus)
		flag.size += ft_align('0', flag.width - 1);
	flag.size += print_char(c);
	if (flag.minus)
		flag.size += ft_align(' ', flag.width - 1);
	return (flag.size);
}