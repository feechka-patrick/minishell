/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmisfit <nmisfit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:30:43 by stune             #+#    #+#             */
/*   Updated: 2021/06/22 15:33:29 by nmisfit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static size_t	ft_start(char const *s1, char const *set)
{
	int		co1;
	int		co2;
	size_t	start;

	co1 = 0;
	start = 0;
	co2 = 0;
	while (s1[co1] != '\0')
	{
		while (set[co2] != '\0')
		{
			if (s1[co1] == set[co2])
			{
				co1++;
				start++;
				co2 = -1;
			}
			co2++;
		}
		co1++;
	}
	return (start);
}

size_t	ft_end(char const *s1, char const *set)
{
	int		co1;
	int		co2;
	size_t	end;
	int		len;

	co1 = 0;
	co2 = 0;
	end = 0;
	len = ft_strlen(s1);
	while (len >= 0)
	{
		while (set[co2] != '\0')
		{
			if (s1[len - 1] == set[co2] && len != 0)
			{
				len--;
				end++;
				co2 = -1;
			}
			co2++;
		}
		len--;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*buf;
	size_t	start;
	size_t	end;
	size_t	len;

	buf = (char *)s1;
	if (!s1 || !set)
		return (buf);
	start = ft_start(s1, set);
	end = ft_end(s1, set);
	len = ft_strlen(s1);
	if (len != start && len != end)
		buf = ft_substr(s1, start, len - start - end);
	else
		buf = ft_calloc(1, 1);
	return (buf);
}
