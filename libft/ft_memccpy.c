/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 13:20:06 by jmendes           #+#    #+#             */
/*   Updated: 2021/03/04 11:54:31 by jmendes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*str_src;
	unsigned char	*str_dest;
	unsigned int	index;

	str_src = (unsigned char *)src;
	str_dest = (unsigned char *)dest;
	index = 0;
	while (index < n)
	{
		str_dest[index] = str_src[index];
		if ((unsigned char)str_src[index] == (unsigned char)c)
			return (str_dest + index + 1);
		index++;
	}
	return (NULL);
}
