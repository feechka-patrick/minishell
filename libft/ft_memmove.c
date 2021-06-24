/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:22:59 by stune             #+#    #+#             */
/*   Updated: 2020/11/03 19:23:01 by stune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	count;
	char	*chsrc;
	char	*chdst;

	chsrc = (char *)src;
	chdst = (char *)dst;
	count = n - 1;
	while (count < n && count >= 0 && chsrc < chdst)
	{
		chdst[count] = chsrc[count];
		count--;
	}
	if (chsrc > chdst)
	{
		count = 0;
		while (count < n)
		{
			chdst[count] = chsrc[count];
			count++;
		}
	}
	return (chdst);
}
