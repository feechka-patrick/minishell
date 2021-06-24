/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmisfit <nmisfit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 14:47:33 by nmisfit           #+#    #+#             */
/*   Updated: 2021/06/21 20:27:22 by nmisfit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shellmini.h"

static void	free_history(void)
{
	t_node	*ptr;

	ptr = g_all->history->head;
	if (ptr)
	{
		while (ptr->next)
		{
			free(ptr);
			ptr = ptr->next;
		}
	}
	free(g_all->history);
}

static void	free_envp(void)
{
	char	**tmp;

	tmp = g_all->my_envp;
	while (*g_all->my_envp)
		free(*g_all->my_envp++);
	free(tmp);
}

void	_exitn(int status)
{
	term_remote();
	free(g_all->buf);
	free_history();
	free(g_all->term);
	free_envp();
	exit(status);
}
