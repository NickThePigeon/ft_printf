/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 19:30:24 by nicky         #+#    #+#                 */
/*   Updated: 2020/11/29 12:57:05 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_toupper(int argument)
{
	if (argument >= 97 && argument <= 122)
	{
		argument -= 32;
		return (argument);
	}
	else
	{
		return (argument);
	}
}
