/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmisfit <nmisfit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 15:31:26 by nmisfit           #+#    #+#             */
/*   Updated: 2021/06/22 15:21:31 by nmisfit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shellmini.h"

void	strzero(char **str, int n)
{
	int	i;

	i = 0;
	while ((*str)[i] && n-- > 0)
		(*str)[i++] = '\0';
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
}

void	my_strjoin(char **buf, char *str)
{
	int		i;
	char	*tmp;

	tmp = (char *)malloc(ft_strlen(*buf) + ft_strlen(str) + 1);
	if (!str || !buf)
		return ;
	i = -1;
	while ((*buf)[++i])
		tmp[i] = (*buf)[i];
	while (*str)
		tmp[i++] = *str++;
	tmp[i] = '\0';
	free(*buf);
	buf = &tmp;
}

void	update_exit_status(char ***envp, int status)
{
	char	*envparams;
	char	*value;

	value = ft_itoa(status);
	envparams = new_envparams("?", value);
	add_envp(envparams, envp);
	free(envparams);
	free(value);
}

void	ft_strjchr(char **str, char c)
{
	char	*tmp;
	int		i;

	if (c == '\n')
		return ;
	tmp = (char *)malloc(ft_strlen(*str) + 2);
	i = 0;
	if (!(*str))
	{
		*str = (char *)malloc(1);
		**str = 0;
	}
	while ((*str)[i] && c != '\n')
	{
		tmp[i] = (*str)[i];
		i++;
	}
	tmp[i++] = c;
	tmp[i] = '\0';
	free(*str);
	*str = tmp;
}
