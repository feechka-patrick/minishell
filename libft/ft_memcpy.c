/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:51:24 by stune             #+#    #+#             */
/*   Updated: 2020/11/03 17:51:27 by stune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	count;
	char	*chsrc;
	char	*chdst;

	chsrc = (char *)src;
	chdst = (char *)dst;
	count = n - 1;
	if (chsrc != NULL || chdst != NULL)
	{
		while (count < n && count >= 0)
		{
			chdst[count] = chsrc[count];
			count--;
		}
		return (chdst);
	}
	return (0);
}
