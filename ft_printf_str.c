/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyou <juyou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 15:02:47 by juyou             #+#    #+#             */
/*   Updated: 2021/06/10 12:00:10 by juyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *str, int len)
{
	if (len == 0)
		return (0);
	return (write(1, str, len));
}

int ft_printf_str(char *str, struct s_flags flag)
{
	int b_len; // 출력할 폭 길이

	if (str == NULL)
		str = "(null)";
	flag.str_len = ft_strlen(str);
	// 정밀도 > 문자열 크기 = 정밀도는 무시되고 문자열이 그대로 출력된다.
	if (flag.precision && flag.precision > flag.str_len)
		flag.precision = flag.str_len;

	// 정밀도가 더 작다면, 정밀도 크기만큼만 출력한다.
	if (flag.dot && flag.precision < flag.str_len) // dot체크는 왜 해애할까...
		(b_len = flag.width - flag.precision);
	// 그게 아니라면 
	else
		b_len = flag.width - flag.str_len;

		// 오른쪽 정렬 + 0없고 + 폭이 있다면 - > 폭을 len만큼 출력
	if (!flag.minus && !flag.zero && flag.width > 0)
		flag.size += ft_align(' ', b_len);
		// 0이 있고, 오른쪽 정렬이라면 len 만큼 0을 출력
	if (flag.zero && !flag.minus)
		flag.size += ft_align('0', b_len);

// str출력부
		// .이 있으면 -> 정밀도만큼 str출력
	if (flag.dot)
		(flag.size += print_str(str, flag.precision));
		// 정밀도가 없다면 str_len 만큼 출력
	else
		(flag.size += print_str(str, flag.str_len));
	if (flag.minus )
		flag.size += ft_align(' ', b_len);
	return (flag.size);
}