/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_int.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/08 15:51:10 by nicky         #+#    #+#                 */
/*   Updated: 2021/02/15 17:12:52 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_d(t_fam *fam)
{
	int	d;

	d = va_arg(fam->args, int);
	fam->len = count_len_int(d);
	if ((fam->left_align == 1 && fam->zeros == 1) ||
			(fam->prec > 0 && fam->width > 0 && fam->zeros == 1))
		fam->zeros = 0;
	if (fam->prec == -1 && fam->prec_bool == 0)
		fam->prec = 0;
	if (fam->width < 0)
	{
		fam->width *= -1;
		fam->left_align = 1;
	}
	if (fam->zeros == 1 && fam->prec > fam->width)
		fam->width = fam->prec;
	if (d >= 0)
		print_plus(d, fam);
	else if (d < 0)
	{
		d *= -1;
		fam->len++;
		print_minus(d, fam);
	}
}

void	print_u(t_fam *fam)
{
	unsigned int	d;

	d = va_arg(fam->args, unsigned int);
	fam->len = count_len_int(d);
	if ((fam->left_align == 1 && fam->zeros == 0) ||
			(fam->prec > 0 && fam->width > 0 && fam->zeros == 1))
		fam->zeros = 0;
	if (fam->prec == -1 && fam->prec_bool == 0)
		fam->prec = 0;
	if (fam->width < 0)
	{
		fam->width *= -1;
		fam->left_align = 1;
	}
	if (fam->zeros == 1 && fam->prec > fam->width)
		fam->width = fam->prec;
	print_plus(d, fam);
}
