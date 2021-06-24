/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stune <stune@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 17:57:19 by stune             #+#    #+#             */
/*   Updated: 2021/06/24 18:00:52 by stune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shellmini.h"

t_cmd	*cmd_init(char *buf)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	cmd->i = 0;
	if (*buf)
	{
		cmd->du_p0 = dup(0);
		cmd->du_p1 = dup(1);
	}
	cmd->pipe_flag = 0;
	cmd->lst_s.l_size = 0;
	cmd->lst_s.lst_all = NULL;
	return (cmd);
}

void	make_key(char *buf, char **envp, int *i, char **tmp)
{
	char	*dollar_tmp;
	char	*save_tmp;
	int		j;

	j = 0;
	save_tmp = *tmp;
	dollar_tmp = NULL;
	while (buf[*i] && buf[*i] != SPACE && buf[*i] != SEMICOLON \
	&& buf[*i] != PIPE && buf[*i] != QUOTE && \
	buf[*i] != APOSTROPHE && buf[*i] != DOLLAR)
	{
		ft_strjchr(&dollar_tmp, buf[*i]);
		(*i)++;
	}
	ft_strjchr(&dollar_tmp, '=');
	while (envp[j])
	{
		if (!(ft_strncmp(envp[j], dollar_tmp, ft_strlen(dollar_tmp))))
		{
			*tmp = ft_strjoin(*tmp, get_value(envp[j]));
			free(save_tmp);
		}
		j++;
	}
	free(dollar_tmp);
}

void	if_quote(char *buf, char **envp, char **tmp, int *i)
{
	(*i)++;
	while (buf[*i] != QUOTE && buf[*i] != 0)
	{
		if (buf[*i] == DOLLAR)
			dollar_sign_processing(envp, buf, i, tmp);
		if (buf[*i] == BACKSLASH)
		{
			if (buf[*i + 1] == BACKSLASH || buf[*i + 1] == DOLLAR \
					|| buf[*i + 1] == QUOTE)
				(*i)++;
			ft_strjchr(tmp, buf[*i]);
			(*i)++;
		}
		if (buf[*i] != BACKSLASH && buf[*i] != QUOTE)
		{
			ft_strjchr(tmp, buf[*i]);
			(*i)++;
		}
	}
	(*i)++;
}

void	if_apostrophe(char *buf, char **tmp, int *i)
{
	(*i)++;
	while (buf[*i] != APOSTROPHE && buf[*i] != 0)
	{
		ft_strjchr(tmp, buf[*i]);
		(*i)++;
	}
	if (buf[*i] != APOSTROPHE)
		(*i)++;
}

void	if_quo_back_apos_pip(char *buf, char **tmp, char **envp, int *i)
{
	if (buf[*i] == BACKSLASH)
	{
		(*i)++;
		ft_strjchr(tmp, buf[*i]);
		(*i)++;
	}
	if (buf[*i] == QUOTE)
		if_quote(buf, envp, tmp, i);
	if (buf[*i] == APOSTROPHE)
		if_apostrophe(buf, tmp, i);
}
