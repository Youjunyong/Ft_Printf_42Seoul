/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpotter <wpotter@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 16:46:40 by tsecret           #+#    #+#             */
/*   Updated: 2020/07/28 02:00:00 by wpotter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_char(char sym)
{
	return (write(1, &sym, 1));
}

int	ft_align(int sym, int len)
{
	int i_wr;

	i_wr = 0;
	while (len > 0)
	{
		i_wr += print_char(sym);
		len--;
	}
	return (i_wr);
}

int	ft_print_c(char sym, struct s_flags flag)
{
	if (flag.width && !flag.zero && !flag.minus)
		flag.count += ft_align(' ', flag.width - 1);
	else if (flag.zero && !flag.minus)
		flag.count += ft_align('0', flag.width - 1);
	flag.count += print_char(sym);
	if (flag.minus)
		flag.count += ft_align(' ', flag.width - 1);
	return (flag.count);
}
