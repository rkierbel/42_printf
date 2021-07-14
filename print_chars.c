/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkierbel <rkierbel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 14:08:49 by rkierbel          #+#    #+#             */
/*   Updated: 2021/04/29 10:50:58 by rkierbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_percent(t_parser *option)
{
	int	size;

	size = 1;
	option->index++;
	if (option->width <= 0)
		option->width = size;
	else if (option->width > size && option->flag_dash == 0)
	{
		option->width = option->width - size;
		print_padding(option, option->width);
	}
	ft_putchar(option, '%');
	if (option->width > size && option->flag_dash == 1)
	{
		option->width = option->width - size;
		print_padding(option, option->width);
	}
	reset_parser(option);
}

void	print_char(t_parser *option, int c)
{
	option->index++;
	if (option->flag_asterisk == 1)
		option->flag_dash = 1;
	if (option->width <= 0)
		option->width = 1;
	else if (option->width > 1 && option->flag_dash == 0)
	{
		option->padding = ' ';
		print_padding(option, option->width - 1);
	}
	ft_putchar(option, c);
	if (option->width > 1 && option->flag_dash == 1)
		print_padding(option, option->width - 1);
	reset_parser(option);
}

void	print_string(t_parser *option, char *str)
{
	int	size;

	if (!str)
		str = "(null)";
	size = (int)ft_strlen(str);
	option->index++;
	if (option->flag_dot == 1 && option->precision < size)
		size = option->precision;
	if (option->width <= 0)
		option->width = size;
	else if (option->width > size && option->flag_dash == 0)
	{
		if (option->width > option->precision && option->flag_zero == 0)
			option->padding = ' ';
		option->width = option->width - size;
		print_padding(option, option->width);
	}
	ft_putstr(option, str, size);
	if (option->width > size && option->flag_dash == 1)
	{
		option->width = option->width - size;
		print_padding(option, option->width);
	}
	reset_parser(option);
}
