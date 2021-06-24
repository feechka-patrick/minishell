/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _pipe.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stune <stune@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 20:11:48 by stune             #+#    #+#             */
/*   Updated: 2021/06/24 18:02:32 by stune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shellmini.h"

void	pipe_maker(char *argv[], char *envp[])
{
	int	pipe_fd[2];
	int	pid;
	int	status;

	pipe(pipe_fd);
	pid = fork();
	if (pid == 0)
	{
		dup2(pipe_fd[1], 1);
		close(pipe_fd[0]);
		get_utils(argv, &envp);
		close(pipe_fd[1]);
		exit(1);
	}
	else if (pid > 0)
	{
		dup2(pipe_fd[0], 0);
		close(pipe_fd[1]);
		wait(&status);
		close(pipe_fd[0]);
	}
}

void	norm_correct(char *buf, char **tmp, int *i)
{
	if (buf[*i] != QUOTE && buf[*i] != APOSTROPHE && \
	buf[*i] != BACKSLASH && buf[*i] != SEMICOLON \
	&& buf[*i] != SPACE && buf[*i] != PIPE)
		ft_strjchr(tmp, buf[*i]);
	if (buf[*i] != BACKSLASH && buf[*i] != SEMICOLON && buf[*i] != SPACE)
		(*i)++;
}

void	dup_and_close(t_cmd *cmd)
{
	dup2(cmd->du_p0, 0);
	dup2(cmd->du_p1, 1);
	close(cmd->du_p0);
	close(cmd->du_p1);
}
