/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _echo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmisfit <nmisfit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 20:25:19 by nmisfit           #+#    #+#             */
/*   Updated: 2021/06/25 17:34:39 by nmisfit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shellmini.h"

static int	check_option(char *arg)
{
	int	i;

	i = 0;
	if (!arg || !arg[i])
		return (0);
	if (arg[i++] == '-' && arg[i])
	{
		while (arg[i] && arg[i] == 'n')
			i++;
		if (arg[i])
			return (0);
		return (1);
	}
	return (0);
}

void	run_echo_with_option(char **argv)
{
	int	i;

	i = 2;
	while (check_option(argv[i]))
		i++;
	if (argv[i])
		write(1, argv[i], ft_strlen(argv[i]));
	while (argv[i] && argv[++i])
	{
		write(1, " ", 1);
		write(1, argv[i], ft_strlen(argv[i]));
	}
}

void	run_echo_without_option(char **argv)
{
	int	i;

	i = 1;
	write(1, argv[i], ft_strlen(argv[i]));
	while (argv[++i])
	{
		write(1, " ", 1);
		write(1, argv[i], ft_strlen(argv[i]));
	}
	write(1, "\n", 1);
}

void	run_echo(char **argv)
{
	if (argv[1] && check_option(argv[1]))
		run_echo_with_option(argv);
	else if (argv[1])
		run_echo_without_option(argv);
	else
		write(1, "\n", 1);
}
