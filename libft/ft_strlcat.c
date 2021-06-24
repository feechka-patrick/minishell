/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:17:07 by stune             #+#    #+#             */
/*   Updated: 2020/11/02 19:17:10 by stune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	codst;
	size_t	cosrc;
	size_t	count;

	codst = ft_strlen(dst);
	cosrc = ft_strlen(src);
	count = codst;
	if (n == 0 || n < codst)
		return (n + cosrc);
	while (count < n - 1 && *src)
	{
		dst[count] = *src++;
		count++;
	}
	dst[count] = '\0';
	return (codst + cosrc);
}
