/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:09:02 by gbrandon          #+#    #+#             */
/*   Updated: 2018/12/06 16:53:15 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*char_dst;
	unsigned char		*char_src;

	if ((dst == NULL) && (src == NULL))
		return (NULL);
	i = 0;
	char_dst = (unsigned char*)dst;
	char_src = (unsigned char*)src;
	while (i < n)
	{
		*char_dst = *char_src;
		char_dst++;
		char_src++;
		i++;
	}
	return (dst);
}
