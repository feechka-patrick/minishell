/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmisfit <nmisfit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:57:53 by stune             #+#    #+#             */
/*   Updated: 2021/06/22 15:33:03 by nmisfit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*ft_res(const char *s1, const char *s2, size_t n)
{
	char	*res;
	size_t	ncpy;
	size_t	count;

	while (*s1 && n--)
	{
		count = 0;
		res = NULL;
		if (*s1 == s2[count])
		{
			res = (char *)s1;
			ncpy = n + 1;
			while (*s1 == s2[count] && *s1 != '\0' && ncpy--)
			{
				s1++;
				count++;
				if (s2[count] == '\0' && ncpy >= 0)
					return (res);
			}
		}
		if (res)
			s1 = res;
		s1++;
	}
	return (0);
}

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*res;

	if (*s2 == 0)
		return ((char *)s1);
	res = ft_res(s1, s2, n);
	return (res);
}
