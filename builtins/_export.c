/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _export.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmisfit <nmisfit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 18:12:27 by nmisfit           #+#    #+#             */
/*   Updated: 2021/06/25 18:39:21 by nmisfit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shellmini.h"

static void	show_envp(char **envp)
{
	char	*str;
	int		i;
	int		j;

	str = "declare -x ";
	i = -1;
	while (envp[++i])
	{
		write(1, str, ft_strlen(str));
		j = 0;
		while (envp[i][j] != '=' && envp[i][j])
			write(1, &envp[i][j++], 1);
		if (envp[i][j])
		{
			write(1, &envp[i][j++], 1);
			write(1, "\"", 1);
			while (envp[i][j])
				write(1, &envp[i][j++], 1);
			write(1, "\"", 1);
		}
		write(1, "\n", 1);
	}
}

static void	sort_envp(char ***envp)
{
	int		i;
	int		j;
	int		size;
	char	*temp;

	size = 0;
	while ((*envp)[size])
		size++;
	i = 0;
	j = size - 1;
	while (i < size - 1)
	{
		while (j > i)
		{
			if (ft_strcmp((*envp)[j - 1], (*envp)[j]) > 0)
			{
				temp = (*envp)[j - 1];
				(*envp)[j - 1] = (*envp)[j];
				(*envp)[j] = temp;
			}
			j--;
		}
		i++;
	}
}

static int	check_argv(char *argv)
{
	if (check_key(argv) == EXPORT_ARG_ERROR
		|| check_value(argv) == EXPORT_ARG_ERROR)
		return (EXPORT_ARG_ERROR);
	return (OK);
}

char	*new_envparams(char *key, char *value)
{
	char	*str;
	int		i;

	str = (char *)malloc(ft_strlen(key) + ft_strlen(value) + 2);
	i = 0;
	while (*key)
		str[i++] = *key++;
	if (value)
	{
		str[i++] = '=';
		while (*value)
			str[i++] = *value++;
	}
	str[i] = '\0';
	return (str);
}

void	run_export(char **argv, char ***envp)
{
	int	i;

	i = 0;
	if (!argv[1])
	{
		show_envp(*envp);
		return ;
	}
	while (argv[++i])
	{
		if (check_argv(argv[i]) != OK)
			errors_output(EXPORT_ARG_ERROR, argv[i]);
		else
			add_envp(argv[i], envp);
	}
	sort_envp(envp);
}
