/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 13:20:09 by nicky         #+#    #+#                 */
/*   Updated: 2020/10/31 13:26:14 by nduijf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *dest, int val, size_t len)
{
	unsigned char *ptr;

	ptr = dest;
	while (len > 0)
	{
		*ptr = val;
		ptr++;
		len--;
	}
	return (dest);
}
