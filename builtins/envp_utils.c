/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stune <stune@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 18:06:26 by nmisfit           #+#    #+#             */
/*   Updated: 2021/06/22 20:02:44 by stune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shellmini.h"

char	*getenvp(char *key, char **envp)
{
	int		i;
	char	*tmp;

	i = -1;
	while (envp[++i])
	{
		tmp = get_key(envp[i]);
		if (!ft_strcmp(key, tmp))
			return (get_value(envp[i]));
		free(tmp);
	}
	return (NULL);
}
