/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stune <stune@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:17:36 by stune             #+#    #+#             */
/*   Updated: 2021/05/22 20:18:29 by stune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*buf;
	int		count;

	count = 0;
	buf = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (buf == NULL)
		return (NULL);
	while (s1[count] != '\0')
	{
		buf[count] = s1[count];
		count++;
	}
	buf[count] = '\0';
	return (buf);
}
