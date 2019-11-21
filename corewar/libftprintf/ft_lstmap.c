/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 12:47:47 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/09 21:28:57 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"

static void		del_link(void *link, size_t size)
{
	size = 0;
	if (!link)
		return ;
	free(link);
	link = NULL;
}

static t_list	*set_head(t_list **lst, t_list *(*f)(t_list *elem))
{
	t_list		*head;
	t_list		*t;

	if (!lst || !(*lst) || !f)
		return (NULL);
	while (*lst)
	{
		if ((t = f(*lst)))
		{
			if (!(head = ft_lstnew(t->content, t->content_size)))
				return (NULL);
			*lst = (*lst)->next;
			return (head);
		}
		*lst = (*lst)->next;
	}
	return (NULL);
}

static t_list	*main_proc(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*t;
	t_list		*cur;
	t_list		*head;

	if (!(head = set_head(&lst, f)))
		return (NULL);
	cur = head;
	while (lst)
	{
		if ((t = f(lst)))
		{
			if (!(cur->next = ft_lstnew(t->content, t->content_size)))
			{
				ft_lstdel(&head, del_link);
				return (NULL);
			}
			cur = cur->next;
		}
		lst = lst->next;
	}
	return (head);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*head;

	if (!lst || !f)
		return (NULL);
	if (!(head = main_proc(lst, f)))
		return (NULL);
	return (head);
}
