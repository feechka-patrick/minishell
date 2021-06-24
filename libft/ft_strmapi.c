/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmisfit <nmisfit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 18:29:52 by stune             #+#    #+#             */
/*   Updated: 2021/06/22 15:32:45 by nmisfit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*buf;
	int		count;
	int		len;

	count = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	buf = (char *)malloc(sizeof(char) * len + 1);
	if (!buf)
		return (NULL);
	while (count < len)
	{
		buf[count] = f(count, s[count]);
		count++;
	}
	buf[count] = '\0';
	return (buf);
}
