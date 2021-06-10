/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyou <juyou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:22:44 by juyou             #+#    #+#             */
/*   Updated: 2021/06/10 14:29:55 by juyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int			ft_itoa(int c, struct s_flags flag)
{
	char		*str;
	int			i;
	long long	number;

	number = (long long)c;
	i = numeric(number);
	if (!(str = (char *)malloc((i + 1) * sizeof(char))))
		return (0);
	if (number < 0)
	{
		str[0] = '-';
		number = -number;
	}
	str[i--] = '\0';
	while (number > 9)
	{
		str[i] = (char)((number % 10) + '0');
		number /= 10;
		i--;
	}
	str[i] = (char)number + '0';
	i = ft_printf_int(str, flag);
	free(str);
	return (i);
}

int			ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int			ft_atoi(const char *s)
{
	unsigned long	num;
	short			sign;
	int				i;

	num = 0;
	sign = 1;
	i = 0;
	while (s[i] == '\t' || s[i] == '\n' || s[i] == '\v'
		|| s[i] == '\f' || s[i] == '\r' || s[i] == ' ')
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i++] == '-')
			sign = -1;
	}
	while (s[i] >= '0' && s[i] <= '9')
		num = num * 10 + s[i++] - '0';
	if (num > 9223372036854775807)
	{
		if (sign == 1)
			return (-1);
		else
			return (0);
	}
	return (num * sign);
}

int			ft_strlen(const char *s)
{
	int len;

	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}
