/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpotter <wpotter@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 18:10:33 by tsecret           #+#    #+#             */
/*   Updated: 2020/07/28 01:50:50 by wpotter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		num_base(unsigned long int c, int buf)
{
	int num;

	num = 0;
	if (c == 0)
		return (1);
	while (c != 0)
	{
		c /= buf;
		num++;
	}
	return (num);
}

char	*ft_utoa(unsigned int num, int buf, int radix)
{
	char	*list;
	int		i;

	i = num_base(num, buf);
	if (!(list = (char *)malloc((i + 1) * sizeof(char))))
		return (NULL);
	list[i--] = '\0';
	if (num == 0)
		list[i] = '0';
	while (num != 0)
	{
		list[i] = "0123456789abcdef"[num % buf];
		num /= buf;
		i--;
	}
	if (radix)
		while ((list[++i] != '\0'))
			list[i] = ft_toupper(list[i]);
	return (list);
}
