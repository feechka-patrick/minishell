/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _execve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmisfit <nmisfit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 19:01:38 by nmisfit           #+#    #+#             */
/*   Updated: 2021/06/25 19:32:27 by nmisfit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shellmini.h"

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

static void	check_status(int status)
{
	if (WTERMSIG(status) == SIGINT)
	{
		write(1, "\n", 1);
		update_exit_status(&(g_all->my_envp), 130);
	}
	if (WTERMSIG(status) == SIGQUIT)
	{
		write(1, "Quit: 3\n", 9);
		update_exit_status(&(g_all->my_envp), 131);
	}
	if (WIFEXITED(status))
		update_exit_status(&(g_all->my_envp), WEXITSTATUS(status));
}

void	_execve(char **argv, char ***envp)
{
	int	pid;
	int	status;

	pid = fork();
	term_remote_with_signal();
	if (pid == -1)
		_exitn(1);
	else if (pid > 0)
	{
		wait(&status);
		signal(SIGINT, sig_handler);
		signal(SIGQUIT, sig_handler);
	}
	else
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		if (execve(getfntpath(argv[0], *envp), argv, *envp) == -1)
		{
			errors_output(found_path(), argv[0]);
			exit(127);
		}
	}
	term_init();
	check_status(status);
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
