/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _exit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmisfit <nmisfit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 15:27:20 by nmisfit           #+#    #+#             */
/*   Updated: 2021/06/22 13:21:56 by nmisfit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shellmini.h"

long long	atoi_for_exit(const char *nptr, int *over)
{
	int				sign;
	unsigned long	result;
	unsigned int	i;

	sign = 1;
	i = 0;
	*over = 0;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	result = 0;
	while (ft_isdigit(nptr[i]))
	{
		result = result * 10 + (nptr[i++] - '0');
		if ((result > 9223372036854775807 && sign == 1)
			|| (result > 9223372036854775808U && sign == -1))
			*over = 1;
	}
	return (result * sign);
}

void	str_isnt_digit(char *str, int *result)
{
	int	i;

	i = -1;
	*result = 0;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			*result = 1;
	}
}

void	run_exit(char **argv)
{
	long long	number;
	int			overflow;
	int			argcheck;

	write(1, "exit\n", 5);
	if (argv)
	{
		if (argv[1] && argv[2])
			return (errors_output(ARG_COUNT_ERROR, argv[0]));
		if (argv[1])
		{
			str_isnt_digit(argv[1], &argcheck);
			number = atoi_for_exit(argv[1], &overflow);
			if (argcheck || overflow)
			{
				printf("nmistune: exit: %s: numeric argument required\n",
					argv[1]);
				_exitn(255);
			}
			_exitn(number % 256);
		}
	}
	_exitn(0);
}
