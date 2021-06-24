/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stune <stune@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:57:38 by nmisfit           #+#    #+#             */
/*   Updated: 2021/06/22 20:03:48 by stune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shellmini.h"

t_node	*create_new_node(char *str)
{
	t_node	*lst;

	lst = (t_node *)malloc(sizeof(t_node));
	lst->data = ft_strdup(str);
	lst->next = NULL;
	lst->prev = NULL;
	return (lst);
}

t_dlist	*attend(t_dlist *lst, char *str)
{
	t_node	*current;
	t_node	*node;

	if (*str == '\0' || *str == '\t')
		return (lst);
	node = create_new_node(str);
	if (!(lst->head))
		lst->head = node;
	else
	{
		current = lst->head;
		while (current->next != NULL)
			current = current->next;
		current->next = node;
		node->prev = current;
	}
	lst->last = node;
	lst->current = NULL;
	if (lst->old_str)
		free(lst->old_str);
	lst->old_str = NULL;
	return (lst);
}
