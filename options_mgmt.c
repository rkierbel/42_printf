/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_mgmt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkierbel <rkierbel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:25:15 by rkierbel          #+#    #+#             */
/*   Updated: 2021/04/29 15:01:23 by rkierbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_specifier(t_parser *option, va_list args)
{
	if (option->type == '%')
		print_percent(option);
	else if (option->type == 'c')
		print_char(option, (va_arg(args, int)));
	else if (option->type == 's')
		print_string(option, (va_arg(args, char *)));
	else if (option->type == 'd' || option->type == 'i')
		print_decimal_int(option, (va_arg(args, int)));
	else if (option->type == 'u')
		print_unsigned(option, (va_arg(args, unsigned)));
	else if (option->type == 'x' || option->type == 'X')
		print_hex(option, (va_arg(args, unsigned int)));
	else if (option->type == 'p')
		manage_ptr(option, (va_arg(args, unsigned long)));
}

void	get_specifier(const char *str, t_parser *option, va_list args)
{
	if (str[option->index] == 'c')
		option->type = 'c';
	else if (str[option->index] == 'd')
		option->type = 'd';
	else if (str[option->index] == 'i')
		option->type = 'i';
	else if (str[option->index] == 's')
		option->type = 's';
	else if (str[option->index] == 'p')
		option->type = 'p';
	else if (str[option->index] == 'u')
		option->type = 'u';
	else if (str[option->index] == 'x')
		option->type = 'x';
	else if (str[option->index] == 'X')
		option->type = 'X';
	else if (str[option->index] == '%')
		option->type = '%';
	print_specifier(option, args);
}

void	manage_other_options(const char *s, t_parser *option, va_list args)
{
	if (s[option->index] == '.')
	{
		option->flag_dot = 1;
		option->index++;
		if (s[option->index] == '*')
			check_asterisk(option, args, &option->precision);
		else if (is_number(s, option) == 1)
			option->precision = option->number;
		else
			option->precision = 0;
	}
	get_specifier(s, option, args);
}

void	manage_options(const char *str, t_parser *option, va_list args)
{
	while (str[option->index] == '0' || str[option->index] == '-')
	{
		if (str[option->index] == '0' && option->flag_dash == 0)
		{
			option->flag_zero = 1;
			option->flag_dash = 0;
			option->padding = '0';
		}
		else if (str[option->index] == '-')
		{
			option->flag_zero = 0;
			option->flag_dash = 1;
			option->padding = ' ';
		}
		option->index++;
	}
	if (str[option->index] == '*')
		check_asterisk(option, args, &option->width);
	else if (is_number(str, option) == 1)
		option->width = option->number;
	manage_other_options(str, option, args);
}
