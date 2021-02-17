/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 09:37:49 by nicky         #+#    #+#                 */
/*   Updated: 2020/11/03 18:04:17 by nduijf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int lenght;

	lenght = ft_strlen(str);
	while (lenght >= 0)
	{
		if (str[lenght] == c)
			return ((char *)&str[lenght]);
		lenght--;
	}
	return (0);
}
