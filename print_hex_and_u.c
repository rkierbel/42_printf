/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_and_u.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkierbel <rkierbel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 14:49:00 by rkierbel          #+#    #+#             */
/*   Updated: 2021/04/29 10:23:40 by rkierbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	precision_positive(t_parser *option, char *number, int size)
{
	if (option->flag_dot == 1 && option->precision > size)
	{
		option->padding = '0';
		print_padding(option, option->precision - size);
	}
	if (option->flag_dot == 1 && option->precision <= 0 && *number == '0')
	{
		if (option->width > size && option->flag_dash == 1)
		{
			option->padding = ' ';
			if (option->precision > size)
				option->width = option->width - option->precision;
			else
				option->width = option->width - size;
			print_padding(option, option->width);
		}
		reset_parser(option);
	}
}

void	print_positive_num(t_parser *option, char *number, int size)
{
	if (option->width <= 0)
		option->width = size;
	else if (option->width > size && option->flag_dash == 0)
	{
		if (option->precision > size)
			option->width = option->width - option->precision;
		else
			option->width = option->width - size;
		print_padding(option, option->width);
	}
	precision_positive(option, number, size);
	ft_putstr(option, number, size);
	if (option->width > size && option->flag_dash == 1)
	{
		option->padding = ' ';
		if (option->precision > size)
			option->width = option->width - option->precision;
		else
			option->width = option->width - size;
		print_padding(option, option->width);
	}
	reset_parser(option);
}

void	print_hex(t_parser *option, unsigned int num)
{
	int		size;
	char	*number;

	option->index++;
	if (option->flag_dot == 1)
	{
		option->flag_zero = 0;
		option->padding = ' ';
	}
	number = hextoa(option, (unsigned long long)num);
	size = (int)ft_strlen(number);
	if (num == 0 && option->flag_dot == 1)
		size = 0;
	print_positive_num(option, number, size);
	free(number);
}

void	print_unsigned(t_parser *option, unsigned int num)
{
	int		size;
	char	*number;

	option->index++;
	if (option->flag_dot == 1)
	{
		option->flag_zero = 0;
		option->padding = ' ';
	}
	number = utoa(num);
	size = (int)ft_strlen(number);
	if (num == 0 && option->flag_dot == 1)
		size = 0;
	print_positive_num(option, number, size);
	free(number);
}
