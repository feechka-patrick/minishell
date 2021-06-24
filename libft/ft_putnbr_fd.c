/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 19:50:07 by stune             #+#    #+#             */
/*   Updated: 2020/11/13 19:50:11 by stune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_putnbr_fd(int n, int fd)
{
	long int	dub;
	long int	neg;

	dub = 0;
	neg = n;
	if (neg < 0)
	{
		neg = neg * -1;
		ft_putchar_fd('-', fd);
	}
	if (neg >= 10)
	{
		dub = dub + neg % 10;
		neg = neg / 10;
		ft_putnbr_fd(neg, fd);
		ft_putchar_fd(dub + 48, fd);
	}
	else
		ft_putchar_fd(neg + 48, fd);
}
