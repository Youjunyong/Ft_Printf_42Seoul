/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyou <juyou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:01:58 by juyou             #+#    #+#             */
/*   Updated: 2021/06/09 17:30:50 by juyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int							check_num(char **str)
{
	int size;

	size = 0;
	if (*str[0] == '-')
		size += print_char(*str[0]);
	if ((*str)[0] == '0' && (*str)[1] == 'x')
		size += print_str("0x", 2);
	(*str) += size;
	return (size);
}

int ft_printf_int(char *str, struct s_flags flag)
{
	int len;
	// 0으로 시작하고, 정밀도가 없고, ?????
	if (str[0] == '0' && !flag.precision && flag.dot)
		str[0] = '\0';
		
	flag.str_len = ft_strlen(str);
	// 정밀도가 출력문자보다 크고, 폭이 없으면 -> len = 정밀도 - 문자길이 (???만큼 0 출력)
	if (flag.precision && flag.precision > flag.str_len && !flag.width)
		len = flag.precision - flag.str_len;
	// 정밀도가 있고, 폭이 있고, 정밀도가 문자길이보다 크면 -> len = 폭 - 정밀도
	else if (flag.precision && flag.width && flag.precision > flag.str_len)
		len = flag.width - flag.precision;
	else
		len = flag.width - flag.str_len;
 
	// -로 시작하고, 정밀도가 문자길이보다 크면, len을 1 낮춰준다. (-를 출력할자리를 만들어준다.)
	if (str[0] == '-' && flag.precision >= flag.str_len)
		len--;

		// 공백 & 0 출력부
	// 폭이 있고, (0이 없거나 .이 없고), 오른쪽 정렬이면 -> len 만큼 공백 출력
	if (flag.width && (!flag.zero || flag.dot) && !flag.minus)
		flag.count += ft_align(' ', len);
	// 0이 있고, 오른쪽 정렬이고, .이 없으면 -> len만큼 0을 출력한다.
	if (flag.zero && !flag.minus && !flag.dot)
		flag.count += check_num(&str) + ft_align('0', len);
	// 정밀도가 문자열보다 크고, dot이 있으면 -> 정밀도 - 문자길이 만큼 0을 출력한다.
	if (flag.precision >= flag.str_len && flag.dot)
		flag.count += check_num(&str) + ft_align('0',
		flag.precision - ft_strlen(str));
	
	// 숫자 출력부
	flag.count += print_str(str, ft_strlen(str));

	
	//폭이 있고 왼쪽 정렬이면 공백을 출력한다.
	if (flag.width && flag.minus)
		flag.count += ft_align(' ', len);
	return (flag.count);
}