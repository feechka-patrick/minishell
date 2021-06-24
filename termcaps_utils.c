/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmisfit <nmisfit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 15:23:24 by nmisfit           #+#    #+#             */
/*   Updated: 2021/06/22 15:26:48 by nmisfit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shellmini.h"

int	putchr(int c)
{
	write(1, &c, 1);
	return (1);
}

void	term_previous(t_term *term, t_dlist *history)
{
	char	*str;

	strzero(&term->ptr, ft_strlen(term->ptr));
	if (history->head)
	{
		tputs(restore_cursor, 1, putchr);
		tputs(tigetstr("ed"), 1, putchr);
		term->ptr -= term->length;
		if (!history->current)
			history->old_str = ft_strdup(term->ptr);
		str = history->last->data;
		history->current = history->last;
		if (history->last->prev)
			history->last = history->last->prev;
		write(1, str, ft_strlen(str));
		strzero(&term->ptr, term->length);
		term->length = ft_strlen(str);
		term->position = term->length;
		while (*str)
			*term->ptr++ = *str++;
	}
}

void	term_next_end_history(char **str, t_dlist *history)
{
	*str = history->old_str;
	if (history->last->next)
		history->last = history->last->next;
	if (history->old_str)
		free(history->old_str);
	history->old_str = NULL;
	history->current = NULL;
}

void	term_next(t_term *term, t_dlist *history)
{
	char	*str;
	char	*tmp;

	strzero(&term->ptr, ft_strlen(term->ptr));
	if (history->current)
	{
		tputs(restore_cursor, 1, putchr);
		tputs(tigetstr("ed"), 1, putchr);
		if (history->current->next)
		{
			str = history->current->next->data;
			history->current = history->current->next;
			history->last = history->last->next;
		}
		else
			term_next_end_history(&str, history);
		write(1, str, ft_strlen(str));
		term->ptr -= term->length;
		strzero(&term->ptr, term->length);
		term->length = ft_strlen(str);
		term->position = term->length;
		tmp = str;
		while (*str)
			*term->ptr++ = *str++;
	}
}

void	term_delete(t_term *term, int length)
{
	char	*tmp;
	int		i;

	strzero(&term->ptr, ft_strlen(term->ptr));
	if (term->position > 0)
	{
		tputs(cursor_left, 1, putchr);
		tputs(delete_character, 1, putchr);
		tmp = term->ptr - term->length + term->position - length;
		i = -1;
		while (tmp[++i + 1])
			tmp[i] = tmp[i + 1];
		tmp[i] = '\0';
		term->position -= length;
		term->ptr -= length;
	}
}
