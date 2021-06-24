/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmisfit <nmisfit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 02:53:17 by nmisfit           #+#    #+#             */
/*   Updated: 2021/06/20 19:56:32 by nmisfit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(char const *s, char c)
{
	unsigned int	count;

	count = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static int	ft_wordlen(char const *s, char c)
{
	unsigned int	length;

	length = 0;
	while (s[length] && s[length] != c)
		length++;
	return (length + 1);
}

int	free_split(char **str, int i)
{
	while (i--)
		free(str[i]);
	free(str);
	return (0);
}

static int	calc_smth(char **s, char c, int i, char **str)
{
	while (**s && **s == c)
		(*s)++;
	str[i] = (char *)malloc(sizeof(char) * ft_wordlen(*s, c));
	if (!str[i])
		return (free_split(str, i));
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char			**str;
	unsigned int	i;
	unsigned int	wd_count;
	unsigned int	index;

	if (!s)
		return (0);
	wd_count = ft_wordcount(s, c);
	str = (char **)malloc(sizeof(char *) * (wd_count + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < wd_count)
	{
		if (!calc_smth((char **)&s, c, i, str))
			return (NULL);
		index = 0;
		while (*s && *s != c)
			str[i][index++] = *s++;
		str[i][index] = '\0';
	}
	str[i] = NULL;
	return (str);
}
