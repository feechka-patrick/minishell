/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stune <stune@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:49:29 by stune             #+#    #+#             */
/*   Updated: 2021/06/23 18:18:34 by stune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shellmini.h"

void	all_init(void)
{
	g_all->buf = (char *)malloc(BUFER_SIZE);
	g_all->history = (t_dlist *)malloc(sizeof(t_dlist));
	g_all->term = (t_term *)malloc(sizeof(t_term));
	g_all->history->head = NULL;
	g_all->history->last = NULL;
	g_all->history->current = NULL;
	g_all->history->old_str = NULL;
	g_all->flag = FLAG_NONE;
	term_init();
}

void	update_term_line(void)
{
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);
	strzero(&(g_all->buf), ft_strlen(g_all->buf));
	g_all->term->ptr = g_all->buf;
	g_all->term->position = 0;
	write(1, BASH_NAME, ft_strlen(BASH_NAME));
	tputs(save_cursor, 1, putchr);
}

void	search_command(t_dlist *history, char *buf, int length, t_term *term)
{
	if (!ft_strcmp(term->ptr, UP))
		term_previous(term, history);
	else if (!ft_strcmp(term->ptr, DOWN))
		term_next(term, history);
	else if (!ft_strcmp(term->ptr, BKSP))
		term_delete(term, length);
	else if (!ft_strcmp(term->ptr, LEFT))
		term_left(term);
	else if (!ft_strcmp(term->ptr, RIGHT))
		term_right(term);
	else if (!ft_strcmp(buf, CTRLD))
	{
		write(1, "exit\n", 5);
		_exitn(0);
	}
	else if (ft_strcmp(term->ptr, "\n")
		&& ft_strcmp(term->ptr, RIGHT)
		&& ft_strcmp(term->ptr, LEFT)
		&& term->position == term->length)
	{
		write(1, term->ptr, length);
		term->ptr += length;
		term->position += length;
	}
}

void	newline_process(void)
{
	strzero(&g_all->term->ptr, ft_strlen(g_all->term->ptr));
	attend(g_all->history, g_all->buf);
	write(1, "\n", 1);
	cmd_loop(g_all->buf, &g_all->my_envp);
}

int	main(int argc, char *argv[], char *envp[])
{
	int	length;

	check_count_of_argv(argc, argv);
	g_all = (t_all *)malloc(sizeof(t_all));
	g_all->my_envp = make_my_envp(envp);
	all_init();
	while (1)
	{
		update_term_line();
		while (ft_strcmp(g_all->term->ptr, "\n"))
		{
			strzero(&(g_all->term->ptr), ft_strlen(g_all->term->ptr));
			g_all->term->length = ft_strlen(g_all->buf);
			length = read(0, g_all->term->ptr, 100);
			check_flagc();
			search_command(g_all->history, g_all->buf, length, g_all->term);
		}
		if (!ft_strcmp(g_all->term->ptr, "\n"))
			newline_process();
		strzero(&(g_all->term->ptr), ft_strlen(g_all->term->ptr));
	}
}
