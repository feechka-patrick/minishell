/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmisfit <nmisfit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 18:17:34 by stune             #+#    #+#             */
/*   Updated: 2021/06/23 17:31:33 by nmisfit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shellmini.h"

static void	freeing_memory(t_list_operation *lst_s, char ***my_av)
{
	if (lst_s->l_size)
	{
		ft_lstclear(&lst_s->tmp_list, free);
		free(*my_av);
		*my_av = NULL;
		lst_s->l_size = 0;
	}
}

void	dollar_sign_processing(char **envp, char *buf, int *i, char **tmp)
{
	if (!*tmp)
		*tmp = NULL;
	if (buf[*i] == DOLLAR)
	{
		(*i)++;
		if (buf[*i] >= '0' && buf[*i] <= '9')
		{
			(*i)++;
			return ;
		}
		make_key(buf, envp, i, tmp);
		if (buf[*i] == DOLLAR)
			dollar_sign_processing(envp, buf, i, tmp);
		if (buf[*i] != DOLLAR && buf[*i] != APOSTROPHE \
		&& buf[*i] != SPACE && buf[*i] != SEMICOLON)
			(*i)++;
	}
}

static int	get_arguments(char *buf, int *i, char **tmp, char **envp)
{
	int	pipe_flag;

	pipe_flag = 0;
	while (buf[*i] != 0 && (buf[*i] == SPACE || buf[*i] == '\t'))
		(*i)++;
	while (buf[*i] != 0 && buf[*i] != SPACE \
	&& buf[*i] != SEMICOLON && buf[*i] != '\t')
	{
		if (if_redirect_in_buf(buf, i, tmp))
			return (pipe_flag);
		if_quo_back_apos_pip(buf, tmp, envp, i);
		if (buf[*i] == DOLLAR)
		{
			dollar_sign_processing(envp, buf, i, tmp);
			return (0);
		}
		if (buf[*i] == PIPE)
		{
			pipe_flag = 1;
			break ;
		}
		norm_correct(buf, tmp, i);
	}
	return (pipe_flag);
}

static char	**make_argv(t_list_operation *lst_s, char *tmp, char *buf, int i)
{
	char	**my_av;
	int		j;

	j = 0;
	my_av = NULL;
	if (tmp)
	{
		lst_s->list = ft_lstnew(tmp);
		ft_lstadd_back(&lst_s->lst_all, lst_s->list);
	}
	if (buf[i] == 0 || buf[i] == SEMICOLON || buf[i] == PIPE)
		lst_s->l_size = ft_lstsize(lst_s->lst_all);
	if (lst_s->l_size)
	{
		lst_s->tmp_list = lst_s->lst_all;
		my_av = malloc(sizeof(char *) * lst_s->l_size + 1);
		while (lst_s->lst_all)
		{
			my_av[j] = lst_s->lst_all->content;
			lst_s->lst_all = lst_s->lst_all->next;
			j++;
		}
		my_av[j] = NULL;
	}
	return (my_av);
}

void	cmd_loop(char *buf, char ***envp)
{
	t_cmd	*cmd;
	int		i;

	cmd = cmd_init();
	i = 0;
	while (buf[i] != 0)
	{
		cmd->tmp = NULL;
		cmd->pipe_flag = get_arguments(buf, &i, &cmd->tmp, *envp);
		cmd->my_av = make_argv(&cmd->lst_s, cmd->tmp, buf, i);
		if (check_errors(buf, cmd->my_av, i))
			return ;
		if (cmd->pipe_flag == 0)
			get_utils(cmd->my_av, envp);
		else
			pipe_maker(cmd->my_av, *envp);
		if (buf[i] == SEMICOLON || buf[i] == 0)
		{
			dup2(cmd->du_p0, 0);
			dup2(cmd->du_p1, 1);
		}
		if (buf[i] == PIPE || buf[i] == SEMICOLON)
			i++;
		freeing_memory(&cmd->lst_s, &cmd->my_av);
		free(cmd);
	}
}
