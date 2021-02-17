/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 14:37:31 by nicky         #+#    #+#                 */
/*   Updated: 2020/11/29 12:55:51 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_isalnum(int argument)
{
	if ((argument >= 'a' && argument <= 'z') ||
			(argument >= 'A' && argument <= 'Z') ||
				(argument >= '0' && argument <= '9'))
		return (1);
	else
		return (0);
}
