/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyou <juyou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:42:34 by juyou             #+#    #+#             */
/*   Updated: 2021/06/10 00:22:06 by juyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



int							print_pointer(char *str, struct s_flags flags)
{
	flags.str_len = ft_strlen(str);

	// NULL인경우에 걸리지 않도록 하기 위해서 flags.dot 조건을 추가해야한다.
	if (flags.dot && str[2] == '0') 
	// ("%p", NULL); [ 0x0 | 0x ]
	//       expected output : "0x0"
	//       your output     : "0x"
	//("%5p", NULL) ;
	//       expected output : "  0x0"
	//       your output     : "   0x"
	{
		flags.str_len--;
	}

	if (flags.dot && flags.precision > flags.width)
		flags.str_len -= 2;
	
	// 정밀도 없는 NULL은 여기서 걸린다.	
	if (flags.width && !flags.minus && !flags.zero && !flags.dot)
			flags.count += ft_align(' ', flags.width - flags.str_len);
	
	else if (flags.width && (flags.dot || !flags.zero) && !flags.minus)
	{
		if (flags.str_len < flags.precision)
			flags.count += ft_align(' ', flags.width - flags.precision);
		else
			flags.count += ft_align(' ', flags.width - flags.str_len);
	}
	
	if (flags.zero && flags.width && !flags.minus && !flags.dot)
		flags.count += check_num(&str) +
			ft_align('0', flags.width - flags.str_len);
	if (flags.precision > flags.str_len && flags.dot)
		flags.count += check_num(&str) +
			ft_align('0', flags.precision - flags.str_len);
	flags.count += print_str(str, flags.str_len);
	if (flags.minus)
		flags.count += ft_align(' ', flags.precision >= flags.str_len
		? flags.width - flags.precision : flags.width - flags.str_len);
	return (flags.count);
}

static unsigned long		len_hex(unsigned long int nb)
{
	// 16으로 나누어
	size_t i;

	i = 0;
	while (nb >= 16)
	{
		nb /= 16;
		i++;
	}
	return (i + 1);
}

size_t						ft_pointer(unsigned long ptrp, struct s_flags flag)
{
	size_t		i;
	char		*str;

	i = 2 + len_hex(ptrp);
	if (!(str = (char *)malloc((i + 1) * sizeof(char))))
		return (0);
	//맨뒤에 널 삽입
	str[i--] = '\0';

	//가변인자 값이 0, NULL 경우는 0삽입
	if (ptrp == 0)
		str[i--] = '0';
	
	while (ptrp != 0)
	{
		str[i] = "0123456789abcdef"[ptrp % 16];
		ptrp /= 16;
		i--;
	}
	str[i--] = 'x';
	str[i] = '0';
	i = print_pointer(str, flag);
	free(str);
	return (i);
}