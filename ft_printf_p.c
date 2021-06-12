/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyou <juyou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:42:34 by juyou             #+#    #+#             */
/*   Updated: 2021/06/12 14:16:26 by juyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int							print_pointer(char *str, struct s_flags flags)
{
	flags.str_len = ft_strlen(str);
	if (flags.dot && str[2] == '0') 
		flags.str_len--;
	if (flags.dot && flags.precision > flags.width)
		flags.str_len -= 2;
	if (flags.width && !flags.minus && !flags.zero && !flags.dot)
			flags.size += ft_align(' ', flags.width - flags.str_len);
	else if (flags.width && (flags.dot || !flags.zero) && !flags.minus)
	{
		if (flags.str_len < flags.precision)
			flags.size += ft_align(' ', flags.width - flags.precision);
		else
			flags.size += ft_align(' ', flags.width - flags.str_len);
	}
	if (flags.zero && flags.width && !flags.minus && !flags.dot)
		flags.size += check_num(&str) +
			ft_align('0', flags.width - flags.str_len);
	if (flags.precision > flags.str_len && flags.dot)
		flags.size += check_num(&str) +
			ft_align('0', flags.precision - flags.str_len);
	flags.size += print_str(str, flags.str_len);
	if (flags.minus)
		flags.size += ft_align(' ', flags.precision >= flags.str_len
		? flags.width - flags.precision : flags.width - flags.str_len);
	return (flags.size);
}

static unsigned long		len_hex(unsigned long int nb)
{
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
	str[i--] = '\0';
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