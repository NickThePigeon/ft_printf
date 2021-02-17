/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nduijf <nduijf@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 14:46:10 by nduijf        #+#    #+#                 */
/*   Updated: 2020/11/17 17:31:53 by nduijf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void *ptr;

	if (nitems == 0 || size == 0)
	{
		nitems = 1;
		size = 1;
	}
	ptr = malloc(nitems * size);
	if (ptr)
		ft_bzero(ptr, nitems * size);
	return (ptr);
}
