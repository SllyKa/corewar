/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_to_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 11:25:11 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/23 19:21:54 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"

static t_list		*set_head(int *ar, size_t s)
{
	t_list		*head;

	if (ar && (s > 0))
	{
		if (!(head = ft_lstnew(&ar[0], 0)))
			return (NULL);
		return (head);
	}
	return (NULL);
}

t_list				*ft_int_to_lst(int *ar, size_t s)
{
	t_list		*head;
	t_list		*cur;
	size_t		i;

	if (!ar)
		return (NULL);
	if (!(head = set_head(ar, s)))
		return (NULL);
	cur = head;
	i = 1;
	while (i < s)
	{
		if (!(cur->next = ft_lstnew(&ar[i], 0)))
			return (NULL);
		cur = cur->next;
		i++;
	}
	return (head);
}
