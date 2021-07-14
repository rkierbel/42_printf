/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkierbel <rkierbel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 17:09:39 by rkierbel          #+#    #+#             */
/*   Updated: 2021/04/29 14:58:51 by rkierbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_number(const char *str, t_parser *option)
{
	option->number = 0;
	if (!(ft_isdigit((int)str[option->index])))
		return (0);
	while (ft_isdigit((int)str[option->index]))
	{
		option->number = (option->number * 10) + (int)str[option->index] - '0';
		option->index++;
	}
	return (1);
}

void	check_asterisk(t_parser *option, va_list args, int *asterisk)
{
	*asterisk = va_arg(args, int);
	if (*asterisk < 0)
	{
		if (option->flag_dot == 0)
		{
			option->flag_asterisk = 1;
			option->flag_dash = 1;
			*asterisk = *asterisk * (-1);
			option->padding = ' ';
		}
		else
			option->flag_dot = 0;
	}
	option->index++;
}

void	print_padding(t_parser *option, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_putchar(option, option->padding);
		i++;
	}
}

void	reset_parser(t_parser *option)
{
	option->negative = 0;
	option->width = 0;
	option->precision = -1;
	option->flag_dash = 0;
	option->flag_dot = 0;
	option->flag_asterisk = 0;
}
