/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmisfit <nmisfit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:53:07 by stune             #+#    #+#             */
/*   Updated: 2021/06/22 15:29:13 by nmisfit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	*buf;

	buf = (size_t *)malloc(count * size);
	if (buf == NULL)
		return (NULL);
	ft_bzero(buf, count * size);
	return (buf);
}
