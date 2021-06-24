/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_construct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmisfit <nmisfit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 14:51:35 by stune             #+#    #+#             */
/*   Updated: 2021/06/21 20:26:57 by nmisfit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shellmini.h"

char	**make_my_envp(char *envp[])
{
	int		count;
	char	**my_envp;
	char	*oldpwd;

	count = 0;
	while (envp[count])
		count++;
	my_envp = malloc(sizeof(char *) * (count + 2));
	count = 0;
	while (envp[count])
	{
		my_envp[count] = ft_strdup(envp[count]);
		count++;
	}
	my_envp[count++] = ft_strdup("?=0");
	my_envp[count] = NULL;
	oldpwd = new_envparams("OLDPWD", "");
	add_envp(oldpwd, &my_envp);
	free(oldpwd);
	return (my_envp);
}
