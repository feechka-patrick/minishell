/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 20:21:15 by stune             #+#    #+#             */
/*   Updated: 2020/11/09 20:21:17 by stune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	int		count;

	count = 0;
	if (!s || len <= 0 || start >= ft_strlen(s))
		len = 0;
	if (s && len > ft_strlen(&s[start]))
		len = ft_strlen(s) - start;
	sub = (char *)ft_calloc((len + 1), 1);
	if (sub == NULL || !s)
		return (NULL);
	while (start != 0 && start < ft_strlen(s))
	{
		s++;
		start--;
	}
	while (len > 0 && start == 0 && s)
	{
		sub[count] = *s++;
		count++;
		len--;
	}
	return (sub);
}
