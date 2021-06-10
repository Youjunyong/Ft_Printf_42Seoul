/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyou <juyou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:15:45 by juyou             #+#    #+#             */
/*   Updated: 2021/06/10 15:00:32 by juyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

# define TYPE	"csdiupxX%"

struct			s_flags
{
	int			width;
	int			zero;
	int			minus;
	int			precision;
	int			size;
	int			dot;
	int			str_len;
	int			sign_w;
};

int				ft_printf(const char *format, ...);
int				ft_prec(const char **format, va_list ap, struct s_flags *flags);
int				ft_itoa(int c, struct s_flags flag);
int				ft_isdigit(int c);
int				ft_atoi(const char *s);
int				ft_strlen(const char *s);
int				ft_width(const char **format, va_list ap,
				struct s_flags *flags);
int				ft_print_c(char c, struct s_flags flag);
int				print_char(char c);
int				ft_align(int c, int len);
int				num_len(unsigned long int c, int buf);
int				print_str(char *str, int len);
int				ft_printf_str(char *str, struct s_flags flags);
int				check_num(char **str);
int				ft_printf_int(char *str, struct s_flags flag);
int				print_pointer(char *list, struct s_flags flags);
int				ft_uint(va_list ptr, int buf, int flag, struct s_flags flags);
char			*ft_utoa(unsigned int num, int buf, int flag);
int				num_base(unsigned long int c, int buf);

size_t			ft_pointer(unsigned long ptrp, struct s_flags flags);

struct s_flags	ft_flag_init(void);
struct s_flags	parse_flag(const char **format, va_list ap);

#endif
