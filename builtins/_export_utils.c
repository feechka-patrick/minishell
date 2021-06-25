/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _export_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmisfit <nmisfit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:07:58 by nmisfit           #+#    #+#             */
/*   Updated: 2021/06/25 18:24:13 by nmisfit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shellmini.h"

char	*get_key(char *str)
{
	char	*key;
	int		i;

	key = ft_strdup(str);
	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	if (str[i] && str[i] == '=')
		key[i] = '\0';
	return (key);
}

char	*get_value(char *str)
{
	char	*value;
	int		i;

	i = 0;
	value = NULL;
	while (str[i] && str[i] != '=')
		i++;
	if (str[i] && str[i] == '=')
		value = str + i + 1;
	return (value);
}

void	update_value(char **value, char **tmp, char **env, char **key)
{
	if (*value || *tmp == NULL)
	{
		free(*env);
		*env = new_envparams(*key, *value);
	}
	free(*key);
	free(*tmp);
}

static int	find_var(char *argv, char ***envp)
{
	int		i;
	char	*key;
	char	*value;
	char	*tmp;

	key = get_key(argv);
	value = get_value(argv);
	i = -1;
	while ((*envp)[++i])
	{
		tmp = get_key((*envp)[i]);
		if (!ft_strcmp(key, tmp))
		{
			update_value(&value, &tmp, &(*envp)[i], &key);
			return (OK);
		}
		free(tmp);
	}
	free(key);
	return (CMD_NOT_FOUND);
}

void	add_envp(char *value, char ***envp)
{
	char	**tmp;
	int		i;

	if (find_var(value, envp) == OK)
		return ;
	i = 0;
	while ((*envp)[i])
		i++;
	tmp = (char **)malloc((i + 2) * sizeof(char *));
	i = -1;
	while ((*envp)[++i])
	{
		tmp[i] = ft_strdup((*envp)[i]);
		free((*envp)[i]);
	}
	tmp[i++] = ft_strdup(value);
	tmp[i] = NULL;
	free(*envp);
	*envp = tmp;
}
