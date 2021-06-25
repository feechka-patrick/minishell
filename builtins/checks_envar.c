/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_envar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmisfit <nmisfit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 18:38:55 by nmisfit           #+#    #+#             */
/*   Updated: 2021/06/25 18:40:13 by nmisfit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shellmini.h"

int	check_key(char *argv)
{
	int	i;

	if (ft_isdigit(argv[0]))
		return (EXPORT_ARG_ERROR);
	i = -1;
	while (argv[++i] && argv[i] != '=')
	{
		if (!(ft_isdigit(argv[i]) || ft_isalpha(argv[i])
				|| argv[i] == '_'))
			return (EXPORT_ARG_ERROR);
	}
	return (OK);
}

int	check_value(char *argv)
{
	char	*value;
	int		i;

	value = get_value(argv);
	i = -1;
	while (value && value[++i])
	{
		if (!((value[i] >= 32 && value[i] <= 126)
				|| (value[i] >= 7 && value[i] <= 13)))
			return (EXPORT_ARG_ERROR);
	}
	return (OK);
}
