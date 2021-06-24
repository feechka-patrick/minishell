/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _cd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmisfit <nmisfit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 13:02:53 by nmisfit           #+#    #+#             */
/*   Updated: 2021/06/22 14:55:05 by nmisfit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shellmini.h"

static void	update_oldpwd(void)
{
	char	*envparams;
	char	value[100];

	getcwd(value, 100);
	envparams = new_envparams("OLDPWD", value);
	add_envp(envparams, &(g_all->my_envp));
	free(envparams);
}

static void	update_pwd(void)
{
	char	*envparams;
	char	value[100];

	if (!(g_all->flag & FLAG_ERROR))
	{
		getcwd(value, 100);
		envparams = new_envparams("PWD", value);
		add_envp(envparams, &(g_all->my_envp));
		free(envparams);
	}
}

int	find_two_points(char **argv, int i)
{
	if (argv[1][i] == '.' && argv[1][i + 1] && argv[1][i + 1] == '.'
		&& (!argv[1][i + 2] || argv[1][i + 2] == '/'))
		return (1);
	return (0);
}

void	copy_path(char **argv, char **path)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (argv[1][++i])
	{
		if (find_two_points(argv, i))
		{
			getcwd(*path + j, 100);
			get_path_up(path);
			j = ft_strlen(*path);
			i++;
		}
		else
			(*path)[j++] = argv[1][i];
	}
	(*path)[j] = '\0';
}

void	run_cd(char **argv)
{
	char	*path;

	update_oldpwd();
	if (!argv[1])
	{
		path = getenv("HOME");
		if (chdir(path) == -1)
			errors_output(4, argv[0]);
		update_pwd();
		return ;
	}
	path = malloc(500);
	copy_path(argv, &path);
	if (chdir(path) == -1)
	{
		errors_output(4, argv[0]);
	}
	update_pwd();
	free(path);
}
