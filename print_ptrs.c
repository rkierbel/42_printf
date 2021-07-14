/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkierbel <rkierbel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 14:49:13 by rkierbel          #+#    #+#             */
/*   Updated: 2021/04/29 14:55:30 by rkierbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_padding_address(t_parser *option, int size)
{
	if (option->width > size && option->flag_dash == 1)
	{
		option->padding = ' ';
		option->width = option->width - size;
		print_padding(option, option->width);
	}
	reset_parser(option);
}

void	print_address(t_parser *option, char *ptr, int size)
{
	if (option->width <= 0)
		option->width = size;
	else if (option->width > size && option->flag_dash == 0)
	{
		option->width = option->width - size;
		print_padding(option, option->width);
	}
	ft_putstr(option, "0x", 2);
	if (option->flag_dot == 1 && option->precision > size
		&& option->width > option->precision)
	{
		option->width = option->width - option->precision;
		print_padding(option, option->width);
	}
	if (option->flag_dot == 1 && option->precision > size
		&& option->width < option->precision)
	{
		option->padding = '0';
		print_padding(option, option->precision - size + 2);
	}
	ft_putstr(option, ptr, size - 2);
	print_padding_address(option, size);
}

void	manage_ptr(t_parser *option, unsigned long pointer)
{
	int				size;
	char			*ptr;

	option->index++;
	ptr = hextoa(option, pointer);
	size = (int)ft_strlen(ptr) + 2;
	if ((pointer == 0) && option->flag_dot == 1)
		size = 2;
	print_address(option, ptr, size);
	free(ptr);
}
