/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyou <juyou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 00:25:53 by juyou             #+#    #+#             */
/*   Updated: 2021/06/10 14:37:21 by juyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 'A');
	return (c);
}

int			num_len(unsigned long int c, int buf)
{
	int		num;

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

char		*ft_utoa(unsigned int num, int buf, int flag)
{
	char	*str;
	int		i;

	i = num_len(num, buf);
	if (!(str = (char *)malloc((i + 1) * sizeof(char))))
		return (NULL);
	str[i--] = '\0';
	if (num == 0)
		str[i] = '0';
	while (num != 0)
	{
		str[i] = "0123456789abcdef"[num % buf];
		num /= buf;
		i--;
	}
	if (flag)
		while ((str[++i] != '\0'))
			str[i] = ft_toupper(str[i]);
	return (str);
}

int			ft_uint(va_list ap, int buf, int flag, struct s_flags flags)
{
	char *str;

	str = ft_utoa(va_arg(ap, unsigned int), buf, flag);
	flags.str_len = ft_strlen(str);
	if (flags.precision == 0 && flags.dot && str[0] == '0')
		flags.str_len--;
	if (flags.width && !flags.minus && !flags.dot && !flags.zero)
		flags.size += ft_align(' ', flags.width - flags.str_len);
	else if (flags.width && (flags.dot || !flags.zero) && !flags.minus)
		flags.size += ft_align(' ', flags.precision >= flags.str_len
		? flags.width - flags.precision : flags.width - flags.str_len);
	if (flags.zero && !flags.minus && flags.width && !flags.dot)
		flags.size += ft_align('0', flags.width - flags.str_len);
	if (flags.dot)
		flags.size += ft_align('0', flags.precision - flags.str_len);
	flags.size += print_str(str, flags.str_len);
	if (flags.minus)
		flags.size += ft_align(' ', flags.precision >= flags.str_len
		? flags.width - flags.precision : flags.width - flags.str_len);
	free(str);
	return (flags.size);
}
