/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _redirect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stune <stune@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 19:01:16 by stune             #+#    #+#             */
/*   Updated: 2021/06/22 20:05:36 by stune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shellmini.h"

static void	right_redirect(char **argv, int	*fd, int *i)
{
	if (!ft_strcmp(argv[*i], REDIRECT))
	{
		(*i)++;
		*fd = open(argv[*i], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		dup2(*fd, 1);
	}
	if (!ft_strcmp(argv[*i], DOUBLE_REDIRECT))
	{
		(*i)++;
		*fd = open(argv[*i], O_WRONLY | O_CREAT | O_APPEND, 0644);
		dup2(*fd, 1);
	}
}

static void	which_of_redirects(int *i, char **argv, int *fd)
{
	while (argv && argv[*i])
	{
		right_redirect(argv, fd, i);
		if (!ft_strcmp(argv[*i], REV_REDIRECT))
		{
			(*i)++;
			*fd = open(argv[*i], O_RDONLY, 0644);
			if (*fd != -1)
				dup2(*fd, 0);
			else
				break ;
		}
		(*i)++;
		if (argv[*i] != NULL)
			close(*fd);
	}
}

static char	**if_redirect(int flag, char **argv, int i, int *fd)
{
	char	**new_cmd;

	new_cmd = argv;
	if (flag)
	{
		new_cmd = malloc(sizeof(char *) * i + 1);
		i = 0;
		while (argv && (ft_strcmp(argv[i], REDIRECT) && \
		ft_strcmp(argv[i], REV_REDIRECT) && ft_strcmp(argv[i], DOUBLE_REDIRECT) \
		&& ft_strcmp(argv[i], REV_DOUBLE_REDIRECT)))
		{
			new_cmd[i] = argv[i];
			i++;
		}
		new_cmd[i] = NULL;
		which_of_redirects(&i, argv, fd);
		if (*fd == -1)
			errors_output(NO_SUCH_FILE, argv[i]);
	}
	return (new_cmd);
}

char	**check_redirect(char **argv, int *fd)
{
	int		i;
	int		flag;
	char	**new_cmd;

	i = 0;
	flag = 0;
	new_cmd = argv;
	while (argv && argv[i])
	{
		if (!ft_strcmp(argv[i], REDIRECT) || !ft_strcmp(argv[i], REV_REDIRECT) \
					|| !ft_strcmp(argv[i], DOUBLE_REDIRECT) \
				|| !ft_strcmp(argv[i], REV_DOUBLE_REDIRECT))
		{
			flag = 1;
			break ;
		}
		i++;
	}
	new_cmd = if_redirect(flag, argv, i, fd);
	return (new_cmd);
}

int	if_redirect_in_buf(char *buf, int *i, char **tmp)
{
	if (buf[*i] == '>' && buf[*i + 1] == '>')
	{
		if (!*tmp)
		{
			ft_strjchr(tmp, buf[*i]);
			(*i)++;
			ft_strjchr(tmp, buf[*i]);
			(*i)++;
			return (1);
		}
		return (1);
	}
	if (buf[*i] == '>' || buf[*i] == '<')
	{
		if (!*tmp)
		{
			ft_strjchr(tmp, buf[*i]);
			(*i)++;
			return (1);
		}
		return (1);
	}
	return (0);
}
