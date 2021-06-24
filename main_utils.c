/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmisfit <nmisfit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 15:47:36 by nmisfit           #+#    #+#             */
/*   Updated: 2021/06/22 20:16:08 by nmisfit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shellmini.h"

void	check_flagc(void)
{
	int		i;
	char	*tail;

	if (g_all->flag & FLAG_C)
	{
		update_exit_status(&(g_all->my_envp), 1);
		g_all->flag = g_all->flag & ~(FLAG_C);
		i = -1;
		tail = ft_strdup(g_all->term->ptr);
		strzero(&g_all->buf, ft_strlen(g_all->buf));
		g_all->term->ptr = g_all->buf;
		g_all->term->position = 0;
		while (tail[++i])
			g_all->buf[i] = tail[i];
		free(tail);
	}
}

void	sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		g_all->flag = g_all->flag | FLAG_C;
		write(1, "\n", 1);
		write(1, BASH_NAME, ft_strlen(BASH_NAME));
		tputs(save_cursor, 1, putchr);
	}
}

void	check_count_of_argv(int argc, char **argv)
{
	char	*streror;

	streror = ": invalid count of arguments";
	if (argc > 1)
	{
		printf("%s%s%s\n", BASH, argv[0], streror);
		exit(1);
	}
}
