/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:51:38 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/21 14:18:31 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void	*ft_memalloc(size_t size)
{
	void	*new_ptr;
	size_t	i;

	i = 0;
	new_ptr = malloc(size);
	if (!new_ptr)
		return (NULL);
	while (i < size)
	{
		((char*)new_ptr)[i] = 0;
		i++;
	}
	return (new_ptr);
}
