/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyou <juyou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 16:57:50 by tsecret           #+#    #+#             */
/*   Updated: 2021/06/09 21:43:59 by juyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>
# define TYPE "csdiupxX%%"
struct	s_flags
{
	int	width;
	int	zero;
	int	minus;
	int	precision;
	int	count;
	int	dot;
	int	len_list;
	int	sign_w;
};



int		ft_printf(const char *format, ...);
int		ft_strlen(const char *s);
int		ft_print_c(char c, struct s_flags flag);
int		ft_align(int c, int len);
int		ft_width(const char **format, va_list ptr, struct s_flags *flag);
int		print_char(char sym);
int		ft_toupper(int c);
int		print_str(char *s, int len);
int		ft_isdigit(int c);
int		ft_precision(const char **format, va_list ptr, struct s_flags *flag);
int		ft_atoi(const char *s);
int		spec(int c);
int		num_base(unsigned long int c, int buf);
int		ft_hex(va_list ptr, int buf, int flag, struct s_flags flags);
char	*ft_utoa(unsigned int num, int buf, int radix);
int		ft_itoa(int sym, struct s_flags flag);
int		print_pointer(char *list, struct s_flags flags);
size_t	ft_pointer(unsigned long int ptrp, struct s_flags flag);
int		check_sym(char **list);
int		print_d_i(char *list, struct s_flags flag);
int		ft_str(char *list, struct s_flags flag);
struct s_flags	ft_flags(void);
struct s_flags	parse_flags(const char **format, va_list ptr);
char	*ft_strjoin(char *s1, char const *s2);

#endif
