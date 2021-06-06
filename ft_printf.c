/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyou <juyou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 13:51:06 by juyou             #+#    #+#             */
/*   Updated: 2021/06/06 13:52:19 by juyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int		ft_rpintf(const char *fotmat, ...)
{
	va_list ap;

	va_start(ap, fotmat);
	
	if (ft_format((char *)format, &tag, ap) == -1)
		return -1
	return (tag.size) 
}