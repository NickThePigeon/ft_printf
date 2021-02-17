/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   puts.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/08 15:42:34 by nicky         #+#    #+#                 */
/*   Updated: 2021/02/15 23:55:22 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_delimiter(int len, char delim, int print, t_fam *fam)
{
	if (print == 1)
	{
		ft_putchar('-', fam);
	}
	if (fam->prec_bool == 1 && fam->prec == 0)
	{
		while (len > 0)
		{
			ft_putchar(' ', fam);
			len--;
		}
	}
	else
	{
		while (len > 0)
		{
			ft_putchar(delim, fam);
			len--;
		}
	}
}

void		ft_putstr_len(char *s, int len, t_fam *fam)
{
	int i;

	if (!s)
		return ;
	i = 0;
	while (s[i] && i < len)
	{
		ft_putchar(s[i], fam);
		i++;
	}
}

void		ft_putbasenbr(unsigned int num, unsigned int base, t_fam *fam)
{
	char *basestr;

	if (fam->prec_bool == 1 && num == 0 && fam->prec == 0)
		return ;
	if (*fam->format == 'x')
		basestr = "0123456789abcdef";
	else
		basestr = "0123456789ABCDEF";
	if (num >= base)
		ft_putbasenbr(num / base, base, fam);
	ft_putchar(basestr[num % base], fam);
}

void		ft_putbasenbr2(unsigned long long num,
	unsigned int base, t_fam *fam)
{
	char *basestr;

	if (fam->prec_bool == 1 && num == 0 && fam->prec == 0)
		return ;
	basestr = "0123456789abcdef";
	if (num >= base)
		ft_putbasenbr2(num / base, base, fam);
	ft_putchar(basestr[num % base], fam);
}

void		ft_putchar(int n, t_fam *fam)
{
	write(1, &n, 1);
	fam->count++;
}
