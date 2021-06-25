/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmisfit <nmisfit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 14:45:47 by nmisfit           #+#    #+#             */
/*   Updated: 2021/06/25 19:33:01 by nmisfit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shellmini.h"

void	term_init(void)
{
	struct termios	term;

	tcgetattr(0, &term);
	term.c_lflag &= ~(ECHO | ICANON);
	tcsetattr(0, TCSANOW, &term);
	tgetent(0, "xterm-256color");
}

void	term_remote(void)
{
	struct termios	term;

	tcgetattr(0, &term);
	term.c_lflag |= (ECHO);
	term.c_lflag |= (ICANON);
	tcsetattr(0, TCSANOW, &term);
}

int	insert_on_position(t_term *term)
{
	char	*tail;
	int		length;
	char	*tmp;

	tail = ft_strdup(term->ptr + term->position - term->length);
	term->ptr = term->ptr + term->position - term->length;
	length = read(0, term->ptr, 100);
	tmp = tail;
	while (*tail)
		*term->ptr++ = *tail++;
	free(tmp);
	return (length);
}

void	term_left(t_term *term)
{
	if (term->position > 0)
	{
		tputs(cursor_left, 1, putchr);
		term->position--;
	}
}

void	term_right(t_term *term)
{
	if (term->position < term->length)
	{
		tputs(cursor_right, 1, putchr);
		term->position++;
	}
}
