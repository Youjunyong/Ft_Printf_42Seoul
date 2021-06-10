/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpotter <wpotter@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 15:50:17 by tsecret           #+#    #+#             */
/*   Updated: 2020/07/28 02:01:00 by wpotter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_d_i(char *list, struct s_flags flag)
{
	int len;

	if (list[0] == '0' && !flag.precision && flag.dot)
		list[0] = '\0';
	flag.len_list = ft_strlen(list);
	if (flag.precision && flag.precision > flag.len_list && !flag.width)
		len = flag.precision - flag.len_list;
	else if (flag.precision && flag.width && flag.precision > flag.len_list)
		len = flag.width - flag.precision;
	else
		len = flag.width - flag.len_list;
	if (list[0] == '-' && flag.precision >= flag.len_list)
		len--;
	if (flag.width && (!flag.zero || flag.dot) && !flag.minus)
		flag.count += ft_align(' ', len);
	if (flag.zero && !flag.minus && !flag.dot)
		flag.count += check_sym(&list) + ft_align('0', len);
	if (flag.precision >= flag.len_list && flag.dot)
		flag.count += check_sym(&list) + ft_align('0',
		flag.precision - ft_strlen(list));
	flag.count += print_str(list, ft_strlen(list));
	if (flag.width && flag.minus)
		flag.count += ft_align(' ', len);
	return (flag.count);
}
