/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:29:48 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/17 15:52:13 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*new_list;

	if (!(new_list = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		new_list->content = NULL;
		new_list->content_size = 0;
		new_list->next = NULL;
	}
	else
	{
		new_list->content = (void*)content;
		new_list->content_size = content_size;
		new_list->next = NULL;
	}
	return (new_list);
}
