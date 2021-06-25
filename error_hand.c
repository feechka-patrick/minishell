/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_hand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmisfit <nmisfit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:34:19 by stune             #+#    #+#             */
/*   Updated: 2021/06/25 19:21:09 by nmisfit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shellmini.h"

void	errors_output(int my_errno, char *arg0)
{
	char	*streror;

	if (my_errno == CMD_NOT_FOUND)
		streror = ": command not found";
	if (my_errno == SYNTAX_ERROR_1)
		streror = "syntax error near unexpected token ';;'";
	if (my_errno == SYNTAX_ERROR_2)
		streror = "syntax error near unexpected token ';'";
	if (my_errno == NO_SUCH_FILE)
		streror = ": no such file or directory";
	if (my_errno == EXPORT_ARG_ERROR)
		streror = ": not a valid identifier";
	if (my_errno == ARG_COUNT_ERROR)
		streror = ": too many arguments";
	if (my_errno == DOUBLE_PIPE)
		streror = "syntax error near unexpected token '||'";
	if (my_errno == EMPTY_PIPE)
		streror = "syntax error near unexpected token '|'";
	update_exit_status(&(g_all->my_envp), 1);
	if (my_errno == SYNTAX_ERROR_1 || my_errno == SYNTAX_ERROR_2)
		update_exit_status(&(g_all->my_envp), 258);
	printf("%s%s%s\n", BASH, arg0, streror);
}

int	check_errors(char *buf, char **my_av, int i)
{
	if (buf[i] == SEMICOLON && buf[i + 1] == SEMICOLON)
	{
		errors_output(2, " ");
		return (1);
	}
	if (buf[i] == SEMICOLON && !my_av)
	{
		errors_output(3, " ");
		return (1);
	}
	if (buf[i] == PIPE && buf[i + 1] == PIPE)
	{
		errors_output(DOUBLE_PIPE, " ");
		return (1);
	}
	if (buf[i] == PIPE && !my_av)
	{
		errors_output(EMPTY_PIPE, " ");
		return (1);
	}
	return (0);
}
