/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_plus_minus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/15 17:03:13 by nicky         #+#    #+#                 */
/*   Updated: 2021/02/15 17:13:14 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_minus(int d, t_fam *fam)
{
	if (fam->left_align > 0)
	{
		if (fam->prec > fam->len - 1)
			print_delimiter(fam->prec - (fam->len - 1), '0', 1, fam);
		else
			ft_putchar('-', fam);
		ft_putbasenbr(d, 10, fam);
		if (fam->len > fam->prec)
			print_delimiter(fam->width - fam->len, ' ', 0, fam);
		else
			print_delimiter(fam->width - fam->prec - 1, ' ', 0, fam);
	}
	else
		print_minus2(d, fam);
}

void	print_minus2(int d, t_fam *fam)
{
	if (fam->prec_bool == 1 && fam->prec == 0 &&
				fam->width > fam->len)
		print_delimiter(fam->width - fam->len, ' ', 0, fam);
	else if (fam->width > fam->prec && fam->prec >= fam->len)
		print_delimiter(fam->width - fam->prec - 1, ' ', 0, fam);
	else if (fam->width > fam->prec && fam->prec < fam->len && fam->zeros < 1)
		print_delimiter(fam->width - fam->len, ' ', 0, fam);
	if (fam->prec > (fam->len - 1))
		print_delimiter(fam->prec - (fam->len - 1), '0', 1, fam);
	else if ((fam->zeros > 0 && fam->prec_bool == 0) ||
					(fam->zeros > 0 && fam->prec < 0))
		print_delimiter(fam->width - fam->len, '0', 1, fam);
	else
		ft_putchar('-', fam);
	ft_putbasenbr(d, 10, fam);
}

void	print_plus(int d, t_fam *fam)
{
	if (fam->prec_bool == 1 && fam->prec == 0 && d == 0)
		print_delimiter(fam->width, ' ', 0, fam);
	else if (fam->left_align > 0)
	{
		if (fam->prec > fam->len)
			print_delimiter(fam->prec - fam->len, '0', 0, fam);
		ft_putbasenbr(d, 10, fam);
		if (fam->len > fam->prec)
			print_delimiter(fam->width - fam->len, ' ', 0, fam);
		else
			print_delimiter(fam->width - fam->prec, ' ', 0, fam);
	}
	else
		print_plus2(d, fam);
}

void	print_plus2(int d, t_fam *fam)
{
	if (fam->prec_bool == 1 && fam->prec <= 0 &&
				fam->width > fam->len && d == 0 && fam->zeros < 1)
		print_delimiter(fam->width - fam->len, ' ', 0, fam);
	else if (fam->width > fam->prec && fam->prec > fam->len)
		print_delimiter(fam->width - fam->prec, ' ', 0, fam);
	else if (fam->width > fam->prec && fam->prec <= fam->len && fam->zeros < 1)
		print_delimiter(fam->width - fam->len, ' ', 0, fam);
	if (fam->zeros > 0)
		print_delimiter(fam->width - fam->len, '0', 0, fam);
	else if (fam->prec > fam->len)
		print_delimiter(fam->prec - fam->len, '0', 0, fam);
	ft_putbasenbr(d, 10, fam);
}
