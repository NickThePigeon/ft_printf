/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/04 20:39:10 by nicky         #+#    #+#                 */
/*   Updated: 2021/02/18 14:56:42 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialize(t_fam *fam)
{
	fam->left_align = 0;
	fam->zeros = 0;
	fam->width = 0;
	fam->prec = -1;
	fam->prec_bool = 0;
	fam->len = 0;
}

int		ft_printf(const char *format, ...)
{
	va_list		args;
	t_fam		fam;

	if (!format)
		return (-1);
	fam.format = format;
	fam.count = 0;
	va_start(fam.args, format);
	while (*(fam.format))
	{
		if (*fam.format == '%')
			parser(&fam);
		else
			ft_putchar(*fam.format, &fam);
		fam.format++;
	}
	va_end(args);
	return (fam.count);
}
