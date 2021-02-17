/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_x.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/08 15:49:36 by nicky         #+#    #+#                 */
/*   Updated: 2021/02/15 19:15:59 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_p(t_fam *fam)
{
	unsigned long long	p;

	p = va_arg(fam->args, unsigned long long);
	fam->len = ft_get_hex_len(p);
	fam->len += 2;
	if (fam->width < 0)
	{
		fam->width *= -1;
		fam->left_align = 1;
	}
	if ((fam->prec == 0 && fam->prec_bool == 1 && p == 0) ||
			(fam->prec == -1 && fam->prec_bool == 1 && p == 0))
		fam->len--;
	if (fam->left_align > 0)
	{
		ft_putstr_len("0x", 2, fam);
		ft_putbasenbr2(p, 16, fam);
		print_delimiter(fam->width - fam->len, ' ', 0, fam);
	}
	else
		print_p2(fam, p);
}

void	print_p2(t_fam *fam, unsigned long long p)
{
	if (fam->zeros > 0)
		print_delimiter(fam->width - fam->len, '0', 0, fam);
	else
		print_delimiter(fam->width - fam->len, ' ', 0, fam);
	ft_putstr_len("0x", 2, fam);
	ft_putbasenbr2(p, 16, fam);
}

void	print_x(t_fam *fam)
{
	unsigned int	hx;

	hx = va_arg(fam->args, unsigned int);
	fam->len = ft_get_hex_len(hx);
	if ((fam->left_align == 1 && fam->zeros == 1) ||
			(fam->prec > 0 && fam->width < 0 && fam->zeros == 1))
		fam->zeros = 0;
	if (fam->prec == -1 && fam->prec_bool == 0)
		fam->prec = 0;
	if (fam->width < 0)
	{
		fam->width *= -1;
		fam->left_align = 1;
	}
	if (fam->zeros == 1 && fam->prec > 0)
		fam->zeros = 0;
	print_x2(hx, fam);
}

void	print_x2(unsigned long long hx, t_fam *fam)
{
	if (fam->prec_bool == 1 && fam->prec == 0 && hx == 0)
		print_delimiter(fam->width, ' ', 0, fam);
	else if (fam->left_align > 0)
	{
		if (fam->prec > fam->len)
			print_delimiter(fam->prec - fam->len, '0', 0, fam);
		ft_putbasenbr(hx, 16, fam);
		if (fam->len > fam->prec)
			print_delimiter(fam->width - fam->len, ' ', 0, fam);
		else
			print_delimiter(fam->width - fam->prec, ' ', 0, fam);
	}
	else
	{
		if (fam->width > fam->prec && fam->prec > fam->len)
			print_delimiter(fam->width - fam->prec, ' ', 0, fam);
		else if (fam->width > fam->prec &&
				fam->prec <= fam->len && fam->zeros < 1)
			print_delimiter(fam->width - fam->len, ' ', 0, fam);
		if (fam->zeros > 0)
			print_delimiter(fam->width - fam->len, '0', 0, fam);
		else if (fam->prec > fam->len)
			print_delimiter(fam->prec - fam->len, '0', 0, fam);
		ft_putbasenbr(hx, 16, fam);
	}
}
