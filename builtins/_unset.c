/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _unset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmisfit <nmisfit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 20:05:52 by nmisfit           #+#    #+#             */
/*   Updated: 2021/06/25 18:52:11 by nmisfit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shellmini.h"

void	run_unset(char **argv, char ***envp)
{
	char	*tmp;
	int		i;
	int		j;
	int		k;

	k = 0;
	while (argv[++k])
	{
		if (check_key(argv[k]) != OK)
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
