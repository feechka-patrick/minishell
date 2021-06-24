/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 20:27:31 by stune             #+#    #+#             */
/*   Updated: 2020/11/03 20:27:33 by stune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*chs;

	chs = (char *)s;
	while (n)
	{
		if (*chs == c)
			return (chs);
		chs++;
		n--;
	}
	return (0);
}
