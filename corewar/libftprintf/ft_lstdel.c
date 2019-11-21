/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 18:03:52 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/09 21:28:18 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list		*temp;

	if (!alst || !del || !(*alst))
		return ;
	while (*alst)
	{
		temp = (*alst)->next;
		if ((*alst)->content)
			del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = temp;
	}
}
