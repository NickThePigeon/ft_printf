/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_char.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/12 14:54:37 by nicky         #+#    #+#                 */
/*   Updated: 2021/02/15 19:12:42 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_precen(t_fam *fam)
{
	char	c;

	c = '%';
	if (fam->width < 0)
	{
		fam->width *= -1;
		fam->left_align = 1;
	}
	if (fam->left_align == 1)
	{
		ft_putchar(c, fam);
		print_delimiter(fam->width - 1, ' ', 0, fam);
	}
	else
	{
		if (fam->zeros == 1)
			print_delimiter(fam->width - 1, '0', 0, fam);
		else
			print_delimiter(fam->width - 1, ' ', 0, fam);
		ft_putchar(c, fam);
	}
}

void	print_c(t_fam *fam)
{
	char	c;

	c = va_arg(fam->args, int);
	if (fam->width < 0)
	{
		fam->width *= -1;
		fam->left_align = 1;
	}
	if (fam->left_align > 0)
	{
		ft_putchar(c, fam);
		print_delimiter(fam->width - 1, ' ', 0, fam);
	}
	else
	{
		if (fam->zeros > 0)
			print_delimiter(fam->width - 1, '0', 0, fam);
		else
			print_delimiter(fam->width - 1, ' ', 0, fam);
		ft_putchar(c, fam);
	}
}

void	print_s(t_fam *fam)
{
	char *string;

	string = va_arg(fam->args, char *);
	if (!string)
		string = "(null)";
	fam->len = ft_strlen(string);
	if (fam->len > fam->prec && fam->prec >= 0)
		fam->len = fam->prec;
	if (fam->width < 0)
	{
		fam->width *= -1;
		fam->left_align = 1;
	}
	if (fam->left_align > 0)
	{
		ft_putstr_len(string, fam->len, fam);
		print_delimiter(fam->width - fam->len, ' ', 0, fam);
	}
	else
		print_s2(fam, string);
}

void	print_s2(t_fam *fam, char *string)
{
	if (fam->zeros > 0)
		print_delimiter(fam->width - fam->len, '0', 0, fam);
	else
		print_delimiter(fam->width - fam->len, ' ', 0, fam);
	ft_putstr_len(string, fam->len, fam);
}
