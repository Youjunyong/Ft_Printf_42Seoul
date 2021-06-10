/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyou <juyou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 16:57:50 by tsecret           #+#    #+#             */
/*   Updated: 2021/06/10 02:15:49 by juyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>

# define TYPE "csdiupxX%"


struct	s_flags
{
	int	width;
	int	zero;
	int	minus;
	int	precision;
	int	count; // size
	int	dot;
	int	str_len;
	int	sign_w;
} 		;//t_flags


// ft_printf
int		ft_printf(const char *format, ...);

// ft_flag.c
struct s_flags ft_flag_init(void);
struct s_flags	parse_flag(const char **format, va_list ap);


// ft_precision.c
int ft_precision(const char **format, va_list ap, struct s_flags *flag);



// ft_utils.c

int			ft_itoa(int c, struct s_flags flag);

int	ft_isdigit(int c);
int	ft_atoi(const char *s);
int	ft_strlen(const char *s);


//ft_width.c
int ft_width(const char **format, va_list ap, struct s_flags *flag);


//ft_printf_c.c
int	ft_print_c(char c, struct s_flags flag);
int	print_char(char c);
int	ft_align(int c, int len);


// ft_utoa.c
int		num_base(unsigned long int c, int buf);
char	*ft_utoa(unsigned int num, int buf, int radix);


// ft_printf_str.c
int	print_str(char *str, int len);
int ft_printf_str(char *str, struct s_flags flag);


//ft_printf_int.c
int							check_num(char **str);
int ft_printf_int(char *str, struct s_flags flag);

//ft_printf_p.c
int							print_pointer(char *list, struct s_flags flags);
size_t						ft_pointer(unsigned long ptrp, struct s_flags flag);


//ft_printf_uint.c
int	ft_uint(va_list ptr, int buf, int flag, struct s_flags flags);
char	*ft_utoa(unsigned int num, int buf, int radix);
int		num_base(unsigned long int c, int buf);
// int	ft_toupper(int c);

#endif


