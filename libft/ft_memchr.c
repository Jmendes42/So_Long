/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 13:20:38 by jmendes           #+#    #+#             */
/*   Updated: 2021/03/04 11:39:54 by jmendes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	index;
	char	*str;

	index = 0;
	str = (char *)s;
	while (index < n)
	{
		if ((unsigned char)str[index] == (unsigned char)c)
			return ((char *)s + index);
		index++;
	}
	return (NULL);
}
