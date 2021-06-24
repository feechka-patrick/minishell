/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stune <stune@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 14:41:11 by stune             #+#    #+#             */
/*   Updated: 2021/06/22 17:23:25 by stune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buf;
	size_t	count;

	count = 0;
	if (!s1 && !s2)
		return (NULL);
	buf = malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (!buf)
		return (NULL);
	while ((ft_strlen(s1) + ft_strlen(s2)) > count)
	{
		while (s1 && *s1 != '\0')
		{
			buf[count] = *s1++;
			count++;
		}
		while (*s2 != '\0')
		{
			buf[count] = *s2++;
			count++;
		}
	}
	buf[count] = '\0';
	return (buf);
}
