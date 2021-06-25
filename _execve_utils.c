/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _execve_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmisfit <nmisfit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 14:12:30 by nmisfit           #+#    #+#             */
/*   Updated: 2021/06/25 19:33:49 by nmisfit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shellmini.h"

char	*pathjoin(char *dirname, char *name, DIR **dir)
{
	char	*path;
	int		i;

	path = (char *)malloc(ft_strlen(dirname) + ft_strlen(name) + 2);
	i = 0;
	while (*dirname)
		path[i++] = *dirname++;
	path[i++] = '/';
	while (*name)
		path[i++] = *name++;
	path[i] = '\0';
	closedir(*dir);
	return (path);
}

char	*getfntpath(char *name, char **envp)
{
	char			**dirname;
	int				i;
	DIR				*dir;
	struct dirent	*strdir;

	i = -1;
	dirname = ft_split(getenvp("PATH", envp), ':');
	while (dirname && dirname[++i])
	{
		dir = opendir(dirname[i]);
		if (dir)
		{
			strdir = readdir(dir);
			while (strdir)
			{
				if (!ft_strcmp(strdir->d_name, name))
					return (pathjoin(dirname[i], name, &dir));
				strdir = readdir(dir);
			}
			closedir(dir);
		}
	}
	return (name);
}

void	term_remote_with_signal(void)
{
	struct termios	term;

	tcgetattr(0, &term);
	term.c_lflag |= (ECHO);
	term.c_lflag |= (ICANON);
	tcsetattr(0, TCSANOW, &term);
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}
