/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpotter <wpotter@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:40:27 by tsecret           #+#    #+#             */
/*   Updated: 2020/07/28 01:46:14 by wpotter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	numeric(int sym)
{
	int	i;

	i = 0;
	if (sym == 0)
		return (1);
	if (sym < 0)
		i++;
	while (sym != 0)
	{
		sym /= 10;
		i++;
	}
	return (i);
}

int			ft_itoa(int sym, struct s_flags flag)
{
	char		*list;
	int			i;
	long long	number;

	number = (long long)sym;
	i = numeric(number);
	if (!(list = (char *)malloc((i + 1) * sizeof(char))))
		return (0);
	if (number < 0)
	{
		list[0] = '-';
		number = -number;
	}
	list[i--] = '\0';
	while (number > 9)
	{
		list[i] = (char)((number % 10) + '0');
		number /= 10;
		i--;
	}
	list[i] = (char)number + '0';
	i = print_d_i(list, flag);
	free(list);
	return (i);
}
