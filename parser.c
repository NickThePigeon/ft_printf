/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/08 15:47:54 by nicky         #+#    #+#                 */
/*   Updated: 2021/02/19 21:50:23 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parser(t_fam *fam)
{
	initialize(fam);
	fam->format++;
	while (*fam->format == '-' || *fam->format == '0')
	{
		if (*fam->format == '-')
			fam->left_align = 1;
		else if (*fam->format == '0')
			fam->zeros = 1;
		fam->format++;
	}
	while (ft_isdigit(*fam->format) || *fam->format == '*')
	{
		if (*fam->format == '*')
			fam->width = va_arg(fam->args, int);
		else
			fam->width = (fam->width * 10) + (*fam->format - '0');
		fam->format++;
	}
	if (*fam->format == '.')
		parser_prec(fam);
	return (parse_type(fam));
}

void	parse_prec(t_fam *fam)
{
	fam->format++;
	fam->prec = 0;
	fam->prec_bool = 1;
	while (ft_isdigit(*fam->format) || *fam->format == '*')
	{
		if (*fam->format == '*')
			fam->prec = va_arg(fam->args, int);
		else
			fam->prec = (fam->prec * 10) + (*fam->format - '0');
		fam->format++;
	}
}

int		parse_type(t_fam *fam)
{
	if (*fam->format == 'c')
		print_c(fam);
	else if (*fam->format == 's')
		print_s(fam);
	else if (*fam->format == 'p')
		print_p(fam);
	else if (*fam->format == 'd' || *fam->format == 'i')
		print_d(fam);
	else if (*fam->format == 'u')
		print_u(fam);
	else if ((*fam->format == 'x') || (*fam->format == 'X'))
		print_x(fam);
	else if (*fam->format == '%')
		print_precen(fam);
	else
		return (-1);
	return (1);
}
