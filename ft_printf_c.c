/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyou <juyou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:10:34 by juyou             #+#    #+#             */
/*   Updated: 2021/06/10 02:48:29 by juyou            ###   ########.fr       */
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
	// 폭이 있고, 0이 없고, -이 없다면 -> width-1 만큼 공백만큼 출력
	if (flag.width && !flag.zero && !flag.minus)
		flag.count += ft_align(' ', flag.width - 1);
	// 0이 있고, 마이너스가 없다면 -> width-1만큼 0출력
	else if (flag.zero && !flag.minus)
		flag.count += ft_align('0', flag.width - 1);

	flag.count += print_char(c);
	// -가 있으면 -> 왼쪽정렬이므로 c를 출력한 후에 공백을 width-1만큼 출력한다.
	if (flag.minus)
		flag.count += ft_align(' ', flag.width - 1);
	return (flag.count);
}