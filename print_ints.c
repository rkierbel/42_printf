/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ints.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkierbel <rkierbel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 14:24:01 by rkierbel          #+#    #+#             */
/*   Updated: 2021/04/29 14:55:46 by rkierbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	precision_negative(t_parser *option, int size)
{
	ft_putchar(option, '-');
	if (option->flag_dot == 1 && option->precision > size)
	{
		option->padding = '0';
		print_padding(option, option->precision - size);
	}
}

void	print_negative_int(t_parser *option, char *number, int size)
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
	if (option->flag_zero == 0)
		precision_negative(option, size);
	ft_putstr(option, number, size - 1);
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

static void	verify_dec_int(t_parser *option, char *number, int size)
{
	if (option->negative == 1)
	{
		size = size + 1;
		option->precision = option->precision + 1;
	}
	if (option->negative == 1 && option->flag_zero == 1)
	{
		ft_putchar(option, '-');
		print_negative_int(option, number, size);
	}
	else if (option->negative == 1 && option->flag_zero == 0)
		print_negative_int(option, number, size);
	else
		print_positive_num(option, number, size);
	free(number);
}

void	print_decimal_int(t_parser *option, long int num)
{
	int		size;
	char	*number;

	option->index++;
	if (option->flag_dot == 1)
	{
		option->flag_zero = 0;
		option->padding = ' ';
	}
	if (num == INT_MIN)
	{
		num = 2147483648;
		option->negative = 1;
	}
	if (num < 0)
	{
		option->negative = 1;
		num = num * (-1);
	}
	number = ft_itoa(num);
	size = (int)ft_strlen(number);
	if (num == 0 && option->flag_dot == 1)
		size = 0;
	verify_dec_int(option, number, size);
}
