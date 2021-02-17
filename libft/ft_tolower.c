/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 19:24:30 by nicky         #+#    #+#                 */
/*   Updated: 2020/11/29 12:57:05 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_tolower(int argument)
{
	if (argument >= 65 && argument <= 90)
	{
		argument += 32;
		return (argument);
	}
	else
	{
		return (argument);
	}
}
