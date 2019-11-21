/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfold.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 12:07:26 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/09 21:25:54 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		*ft_lstfold(t_list *list, void *(*f)(void *a, void *b))
{
	void		*res;

	if (!list || !f)
		return (NULL);
	res = (void*)list->content;
	while (list && list->next)
	{
		res = (void*)f(res, list->next->content);
		list = list->next;
	}
	return (res);
}
