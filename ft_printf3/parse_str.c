/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyou <juyou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 20:21:32 by tsecret           #+#    #+#             */
/*   Updated: 2021/06/09 16:44:53 by juyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_str(char *list, struct s_flags flag)
{
	int len;

	if (list == NULL)
		list = "(null)";
	flag.len_list = ft_strlen(list);
	if (flag.precision && flag.precision > flag.len_list)
		flag.precision = flag.len_list;
	if (flag.dot && flag.precision < flag.len_list)
		(len = flag.width - flag.precision);
	else
		len = flag.width - flag.len_list;
	if (!flag.minus && !flag.zero && flag.width > 0)
		flag.count += ft_align(' ', len);
	if (flag.zero && !flag.minus)
		flag.count += ft_align('0', len);
	if (flag.dot)
		(flag.count += print_str(list, flag.precision));
	else
		(flag.count += print_str(list, flag.len_list));
	if (flag.minus)
		flag.count += ft_align(' ', len);
	return (flag.count);
}
