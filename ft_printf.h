/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkierbel <rkierbel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:04:02 by rkierbel          #+#    #+#             */
/*   Updated: 2021/04/29 15:00:46 by rkierbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h> 
# include <string.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_parser
{
	char	type;
	char	flag_zero;
	char	flag_dash;
	char	flag_dot;
	char	flag_asterisk;
	char	padding;
	int		width;
	int		precision;
	int		number;
	int		index;
	int		len;
	char	negative;
}				t_parser;

int			ft_printf(const char *format, ...);
void		init_parser(t_parser *option);
void		manage_options(const char *str, t_parser *option, va_list args);
void		manage_other_options(const char *s, t_parser *option, va_list args);
void		get_specifier(const char *str, t_parser *option, va_list args);
void		print_specifier(t_parser *option, va_list args);
void		print_string(t_parser *option, char *str);
void		print_char(t_parser *option, int c);
void		print_percent(t_parser *option);
void		print_decimal_int(t_parser *option, long int num);
void		print_negative_int(t_parser *option, char *number, int size);
void		print_unsigned(t_parser *option, unsigned int num);
void		print_hex(t_parser *option, unsigned int num);
void		print_positive_num(t_parser *option, char *number, int size);
void		manage_ptr(t_parser *option, unsigned long pointer);
void		print_address(t_parser *option, char *ptr, int size);
void		reset_parser(t_parser *option);
void		print_padding(t_parser *option, int len);
void		check_asterisk(t_parser *option, va_list args, int *asterisk);
int			is_number(const char *str, t_parser *option);
int			ft_isdigit(int c);
char		*ft_strdup(const char *s1);
void		ft_putstr(t_parser *option, char *s, size_t size);
size_t		ft_strlen(const char *s);
void		ft_putchar(t_parser *option, char c);
char		*hextoa(t_parser *option, unsigned long long nb);
char		*utoa(unsigned int nb);
char		*ft_itoa(long int nb);

#endif
