/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 11:48:24 by jmendes           #+#    #+#             */
/*   Updated: 2021/03/04 11:51:34 by jmendes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char			*dest1;
	char			*src1;
	unsigned int	index;

	dest1 = (char *)dest;
	src1 = (char *)src;
	index = 0;
	if (!dest && !src)
		return (NULL);
	if (src1 < dest1)
	{
		while (n--)
			dest1[n] = src1[n];
	}
	else
	{
		while (n > 0)
		{
			dest1[index] = src1[index];
			index++;
			n--;
		}
	}
	return (dest);
}
