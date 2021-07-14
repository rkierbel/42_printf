/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkierbel <rkierbel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 15:35:09 by rkierbel          #+#    #+#             */
/*   Updated: 2021/04/29 10:34:46 by rkierbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(t_parser *option, char c)
{
	write(1, &c, 1);
	option->len++;
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_putstr(t_parser *option, char *s, size_t size)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (i < size)
	{
		ft_putchar(option, s[i]);
		i++;
	}
	return ;
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	str = 0;
	i = 0;
	str = (char *)malloc(ft_strlen(s1) + 1);
	if (!str)
		return (0);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}
