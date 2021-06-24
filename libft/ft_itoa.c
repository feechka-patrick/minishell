/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmisfit <nmisfit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 21:21:53 by nmsifit           #+#    #+#             */
/*   Updated: 2021/06/20 19:57:59 by nmisfit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_invert(char *str, int i)
{
	char			buf;
	unsigned int	size;

	size = i - 1;
	i = size / 2;
	while (i >= 0)
	{
		buf = str[i];
		str[i] = str[size - i];
		str[size - i] = buf;
		i--;
	}
	return (str);
}

static int	ft_numlen(long long number)
{
	int				size;

	size = 0;
	if (number == 0)
		return (2);
	while (number != 0)
	{
		number /= 10;
		size++;
	}
	size ++;
	if (size < 0)
		size++;
	return (size);
}

static void	init_prms(int *sign, long long *number, int n)
{
	*sign = 1;
	*number = n;
	if (n < 0)
	{
		*sign *= (-1);
		*number *= (long long)*sign;
	}
}

char	*ft_itoa(int n)
{
	long long		number;
	int				sign;
	char			*str;
	unsigned int	i;

	init_prms(&sign, &number, n);
	str = malloc(sizeof(char) * ft_numlen(number));
	if (!str)
		return (NULL);
	i = 0;
	if (number == 0)
		str[i++] = '0';
	while (number != 0)
	{
		str[i++] = number % 10 + '0';
		number /= 10;
	}
	if (sign < 0)
		str[i++] = '-';
	str[i] = '\0';
	str = ft_invert(str, i);
	return (str);
}
