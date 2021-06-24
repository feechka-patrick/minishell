/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:02:59 by stune             #+#    #+#             */
/*   Updated: 2020/11/03 19:03:02 by stune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			count;
	unsigned char	*chsrc;
	unsigned char	*chdst;
	unsigned char	d;

	chsrc = (unsigned char *)src;
	chdst = (unsigned char *)dst;
	d = c;
	count = 0;
	while (count < n && chsrc[count - 1] != d)
	{
		chdst[count] = chsrc[count];
		count++;
		if (chsrc[count - 1] == d)
			return (&chdst[count]);
	}
	return (0);
}
