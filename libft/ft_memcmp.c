/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 20:46:18 by stune             #+#    #+#             */
/*   Updated: 2020/11/03 20:46:20 by stune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			count;
	int				result;
	unsigned char	*chs1;
	unsigned char	*chs2;

	chs1 = (unsigned char *)s1;
	chs2 = (unsigned char *)s2;
	count = 0;
	result = 0;
	while (count != n)
	{
		if (chs1[count] != chs2[count])
		{
			result = (chs1[count] - chs2[count]);
			return (result);
		}
		count++;
	}
	return (result);
}
