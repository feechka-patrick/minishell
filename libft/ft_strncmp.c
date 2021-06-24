/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 19:07:27 by stune             #+#    #+#             */
/*   Updated: 2020/10/30 19:07:35 by stune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			co;
	int				result;
	unsigned char	*us1;
	unsigned char	*us2;

	co = 0;
	result = 0;
	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	while (co != n && (us1[co] != '\0' || us2[co] != '\0'))
	{
		if (us1[co] != us2[co])
		{
			result = (us1[co] - us2[co]);
			return (result);
		}
		co++;
	}
	return (result);
}
