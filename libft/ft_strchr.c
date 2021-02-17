/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicky <nicky@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 11:30:22 by nicky         #+#    #+#                 */
/*   Updated: 2020/11/29 12:57:05 by nicky         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			return ((char*)&str[i]);
		}
		i++;
	}
	if (c == 0)
		return ((char*)&str[i]);
	else
		return (0);
}
