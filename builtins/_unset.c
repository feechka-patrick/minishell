/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _unset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmisfit <nmisfit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 20:05:52 by nmisfit           #+#    #+#             */
/*   Updated: 2021/06/22 13:04:30 by nmisfit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shellmini.h"

static int	check_argv(char *argv)
{
	int	i;

	if (argv[0] >= '0' && argv[0] <= '9')
		return (EXPORT_ARG_ERROR);
	i = -1;
	while (argv[++i])
	{
		if (!(ft_isdigit(argv[i]) || ft_isalpha(argv[i])
				|| argv[i] == '_' || argv[i] == ';'))
			return (EXPORT_ARG_ERROR);
	}
	return (OK);
}

void	run_unset(char **argv, char ***envp)
{
	char	*tmp;
	int		i;
	int		j;
	int		k;

	k = 0;
	while (argv[++k])
	{
		if (check_argv(argv[k]) != OK)
			errors_output(EXPORT_ARG_ERROR, argv[k]);
		i = -1;
		while ((*envp)[++i])
		{
			tmp = get_key((*envp)[i]);
			if (!ft_strcmp(argv[k], tmp))
			{
				free((*envp)[i]);
				j = i - 1;
				while ((*envp)[++j])
					(*envp)[j] = (*envp)[j + 1];
			}
			free(tmp);
		}
	}
}
