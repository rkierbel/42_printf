/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkierbel <rkierbel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:03:25 by rkierbel          #+#    #+#             */
/*   Updated: 2021/07/14 10:16:19 by rkierbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_parser(t_parser *option)
{
	option->type = 0;
	option->flag_zero = 0;
	option->flag_dash = 0;
	option->flag_dot = 0;
	option->flag_asterisk = 0;
	option->padding = ' ';
	option->width = 0;
	option->precision = -1;
	option->number = 0;
	option->index = 0;
	option->len = 0;
	option->negative = 0;
}

int	ft_printf(const char *format, ...)
{
	const char	*str;
	t_parser	option;
	va_list		args;

	va_start(args, format);
	init_parser(&option);
	str = ft_strdup(format);
	if (!str)
		return (0);
	while (str[option.index])
	{
		if (str[option.index] == '%')
		{
			option.index++;
			manage_options(str, &option, args);
		}
		else
		{
			ft_putchar(&option, str[option.index]);
			option.index++;
		}
	}
	free((char *)str);
	va_end(args);
	return (option.len);
}
