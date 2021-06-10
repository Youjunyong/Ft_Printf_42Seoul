/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyou <juyou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 15:02:41 by tsecret           #+#    #+#             */
/*   Updated: 2021/06/10 12:09:30 by juyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int							check_sym(char **list)
{
	int i;

	i = 0;
	if (*list[0] == '-')
		i += print_char(*list[0]);
	if ((*list)[0] == '0' && (*list)[1] == 'x')
		i += print_str("0x", 2);
	(*list) += i;
	return (i);
}

int							print_pointer(char *list, struct s_flags flags)
{
	flags.len_list = ft_strlen(list);
	if (flags.precision == 0 && flags.dot && list[2] == '0')
		flags.len_list--;
	if (flags.dot && flags.precision > flags.width)
		flags.len_list -= 2;
	if (flags.width && !flags.minus && !flags.zero && !flags.dot)
		flags.count += ft_align(' ', flags.width - flags.len_list);
	else if (flags.width && (flags.dot || !flags.zero) && !flags.minus)
	{
		if (flags.len_list < flags.precision)
			flags.count += ft_align(' ', flags.width - flags.precision);
		else
			flags.count += ft_align(' ', flags.width - flags.len_list);
	}
	if (flags.zero && flags.width && !flags.minus && !flags.dot)
		flags.count += check_sym(&list) +
			ft_align('0', flags.width - flags.len_list);
	if (flags.precision > flags.len_list && flags.dot)
		flags.count += check_sym(&list) +
			ft_align('0', flags.precision - flags.len_list);
	flags.count += print_str(list, flags.len_list);
	if (flags.minus)
		flags.count += ft_align(' ', flags.precision >= flags.len_list
		? flags.width - flags.precision : flags.width - flags.len_list);
	return (flags.count);
}

static unsigned long		len_hex(unsigned long int nb)
{
	size_t i;

	i = 0;
	while (nb >= 16)
	{
		nb = nb / 16;
		i++;
	}
	return (i + 1);
}

size_t						ft_pointer(unsigned long ptrp, struct s_flags flag)
{
	size_t		i;
	char		*list;

	i = 2 + len_hex(ptrp);
	if (!(list = (char *)malloc((i + 1) * sizeof(char))))
		return (0);
	list[i--] = '\0';
	if (ptrp == 0)
		list[i--] = '0';
	while (ptrp != 0)
	{
		list[i] = "0123456789abcdef"[ptrp % 16];
		ptrp /= 16;
		i--;
	}
	list[i--] = 'x';
	list[i] = '0';
	i = print_pointer(list, flag);
	free(list);
	return (i);
}
