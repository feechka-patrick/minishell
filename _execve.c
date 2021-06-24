/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _execve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmisfit <nmisfit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 19:01:38 by nmisfit           #+#    #+#             */
/*   Updated: 2021/06/23 17:35:52 by nmisfit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shellmini.h"

void	sig_dfl(int signal)
{
	if (signal == SIGINT)
	{
		write(1, "\n", 1);
		update_exit_status(&(g_all->my_envp), 130);
	}
	else if (signal == SIGQUIT)
	{
		write(1, "Quit: 3\n", 9);
		update_exit_status(&(g_all->my_envp), 131);
	}
}

int	found_path(void)
{
	int		i;
	char	*tmp;

	i = -1;
	while (g_all->my_envp[++i])
	{
		tmp = get_key(g_all->my_envp[+i]);
		if (!ft_strcmp("PATH", tmp))
		{
			free(tmp);
			return (CMD_NOT_FOUND);
		}
		free(tmp);
	}
	return (NO_SUCH_FILE);
}

void	_execve(char **argv, char ***envp)
{
	int	pid;
	int	status;

	pid = fork();
	term_remote();
	signal(SIGINT, sig_dfl);
	signal(SIGQUIT, sig_dfl);
	if (pid == -1)
		_exitn(1);
	else if (pid > 0)
		wait(&status);
	else
	{
		if (execve(getfntpath(argv[0], *envp), argv, *envp) == -1)
		{
			errors_output(found_path(), argv[0]);
			exit(127);
		}
	}
	term_init();
	if (WIFEXITED(status))
		update_exit_status(envp, WEXITSTATUS(status));
}

void	check_fd(int fd, char **argv)
{
	if (fd > 0)
		close(fd);
	if (fd != 0)
		free(argv);
}

void	get_utils(char **argv, char ***envp)
{
	int	fd;

	fd = 0;
	argv = check_redirect(argv, &fd);
	if (argv && *argv && envp && check_command(argv, envp))
		return (check_fd(fd, argv));
	else
		if (fd != -1)
			_execve(argv, envp);
	check_fd(fd, argv);
}
