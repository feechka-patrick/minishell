/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmisfit <nmisfit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:25:32 by nmisfit           #+#    #+#             */
/*   Updated: 2021/06/22 13:03:25 by nmisfit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shellmini.h"

void	run_pwd(void)
{
	char	path[100];

	getcwd(path, 100);
	write(1, path, ft_strlen(path));
	write(1, "\n", 1);
}

void	get_path_up(char **path)
{
	int	i;

	i = 0;
	while ((*path)[i])
		i++;
	while ((*path)[i] != '/' && i != 0)
		i--;
	if ((*path)[i] == '/')
	{
		while ((*path)[i])
			(*path)[i++] = '\0';
	}
}

void	run_env(char **envp)
{
	int	i;

	i = -1;
	while (envp[++i])
	{
		write(1, envp[i], ft_strlen(envp[i]));
		write(1, "\n", 1);
	}
}

int	check_command(char **argv, char ***envp)
{
	int	result;

	result = 1;
	update_exit_status(envp, 0);
	if (!ft_strcmp(argv[0], "echo"))
		run_echo(argv);
	else if (!ft_strcmp(argv[0], "pwd"))
		run_pwd();
	else if (!ft_strcmp(argv[0], "export"))
		run_export(argv, envp);
	else if (!ft_strcmp(argv[0], "env"))
		run_env(*envp);
	else if (!ft_strcmp(argv[0], "cd"))
		run_cd(argv);
	else if (!ft_strcmp(argv[0], "unset"))
		run_unset(argv, envp);
	else if (!ft_strcmp(argv[0], "exit"))
		run_exit(argv);
	else
		result = 0;
	return (result);
}
