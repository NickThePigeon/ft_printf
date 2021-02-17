/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 14:12:09 by nicky         #+#    #+#                 */
/*   Updated: 2020/11/24 11:10:45 by nduijf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || (c == 32))
		return (1);
	else
		return (0);
}

int			ft_atoi(const char *str)
{
	int min;
	int answer;

	min = 1;
	answer = 0;
	while (ft_isspace(str[0]))
		str++;
	if (str[0] == 45)
		min = min * -1;
	if ((str[0] == 45) || (str[0] == 43))
		str++;
	while (ft_isdigit(str[0]))
	{
		answer = answer * 10 + str[0] - '0';
		str++;
	}
	return (answer * min);
}
