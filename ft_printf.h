/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/04 20:39:13 by nicky         #+#    #+#                 */
/*   Updated: 2021/02/19 21:50:08 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "./libft/libft.h"

typedef struct	s_fam
{
	const char	*format;
	va_list		args;
	int			left_align;
	int			zeros;
	int			width;
	int			prec;
	char		type;
	int			count;
	int			len;
	int			prec_bool;
}				t_fam;

int				ft_printf(const char *format, ...);
int				parse_type(t_fam *fam);
int				parser(t_fam *fam);
void			parse_prec(t_fam *fam);

void			print_s(t_fam *fam);
void			print_s2(t_fam *fam, char *string);
void			print_p(t_fam *fam);
void			print_p2(t_fam *fam, unsigned long long p);
void			print_d(t_fam *fam);
void			print_u(t_fam *fam);
void			print_c(t_fam *fam);
void			print_x(t_fam *fam);
void			print_precen(t_fam *fam);
void			print_minus(int d, t_fam *fam);
void			print_minus2(int d, t_fam *fam);
void			print_plus(int d, t_fam *fam);
void			print_plus2(int d, t_fam *fam);
void			print_x2(unsigned long long hex, t_fam *fam);

int				count_len_int(long long n);
void			print_delimiter(int len, char delim, int print, t_fam *fam);
int				ft_put_hex_nbr(t_fam *fam, unsigned int nbr,
								char *basestr);
int				ft_get_hex_len(unsigned long long hex);
void			print_hex(t_fam *fam);
void			ft_putbasenbr(unsigned int num, unsigned int base, t_fam *fam);
void			ft_putbasenbr2(unsigned long long num,
								unsigned int base, t_fam *fam);
void			ft_putchar(int n, t_fam *fam);
void			ft_putstr_len(char *s, int len, t_fam *fam);

#endif
