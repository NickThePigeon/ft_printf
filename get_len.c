/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_len.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/08 15:46:25 by nicky         #+#    #+#                 */
/*   Updated: 2021/02/15 15:25:15 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_hex_len(unsigned long long hex)
{
	int					base;
	unsigned long long	exp;
	int					len;

	base = 16;
	exp = 1;
	len = 1;
	while (hex / base / exp)
	{
		exp *= base;
		len++;
	}
	return (len);
}

int		count_len_int(long long n)
{
	int			len;
	long long	nbr;

	len = 1;
	if (n == 0)
		return (len);
	if (!n)
		return (0);
	nbr = n;
	if (nbr < 0)
		nbr = nbr * -1;
	while (nbr / 10 > 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}
