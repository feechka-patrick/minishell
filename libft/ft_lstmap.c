/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:59:27 by stune             #+#    #+#             */
/*   Updated: 2020/11/15 18:59:29 by stune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;

	ret = NULL;
	if (!lst)
		return (NULL);
	while (lst)
	{
		ft_lstadd_back(&ret, ft_lstnew(f(lst->content)));
		if (!ret)
		{
			ft_lstclear(&ret, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (ret);
}
