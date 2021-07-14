/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkierbel <rkierbel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 15:41:09 by rkierbel          #+#    #+#             */
/*   Updated: 2021/05/03 14:18:55 by rkierbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	convert_putnbr(long int nb, char *str, long int i)
{
	long unsigned	lu_nb;

	lu_nb = nb;
	if (nb < 0)
	{
		str[0] = '-';
		lu_nb = (lu_nb * (-1));
	}
	if (lu_nb >= 10)
		convert_putnbr((lu_nb / 10), str, (i - 1));
	str[i] = (lu_nb % 10) + '0';
}

char	*ft_itoa(long int nb)
{
	char		*str;
	long int	eq_nb;
	long int	index;

	eq_nb = nb;
	index = 0;
	if (eq_nb <= 0)
		index++;
	while (eq_nb)
	{
		eq_nb = eq_nb / 10;
		index++;
	}
	str = malloc(sizeof(char) * (index + 1));
	if (!str)
		return (NULL);
	str[index] = 0;
	convert_putnbr(nb, str, (index - 1));
	return (str);
}

char	*utoa(unsigned int nb)
{
	unsigned int	index;
	unsigned int	num;
	char			*tmp;

	index = 1;
	num = nb;
	while (nb >= 10 && index++)
		nb = nb / 10;
	tmp = malloc((index + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	*(tmp + index) = '\0';
	while (index--)
	{
		*(tmp + index) = num % 10 + '0';
		num = num / 10;
	}
	return (tmp);
}

static char	*hextoa_next(char *str, t_parser *option, unsigned long long tmp,
					int index)
{
	while (tmp != 0)
	{
		if ((option->type == 'x' || option->type == 'p') && (tmp % 16) >= 10)
			str[index - 1] = (tmp % 16) + 87;
		else if (option->type == 'X' && (tmp % 16) >= 10)
			str[index - 1] = (tmp % 16) + 55;
		else
			str[index - 1] = (tmp % 16) + 48;
		tmp = tmp / 16;
		index--;
	}
	return (str);
}

char	*hextoa(t_parser *option, unsigned long long nb)
{
	int					index;
	char				*str;
	unsigned long long	tmp;

	tmp = nb;
	index = 0;
	if (nb == 0)
		return (ft_strdup("0"));
	while (nb != 0)
	{
		nb = nb / 16;
		index++;
	}
	str = malloc(sizeof(char) * (index + 1));
	if (!str)
		return (NULL);
	str[index] = '\0';
	str = hextoa_next(str, option, tmp, index);
	return (str);
}
