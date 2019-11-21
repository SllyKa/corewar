/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:26:22 by gbrandon          #+#    #+#             */
/*   Updated: 2018/12/03 13:37:44 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*ch_dst;
	char	*ch_src;
	size_t	i;

	i = 0;
	ch_dst = (char*)dst;
	ch_src = (char*)src;
	if (dst != src)
	{
		if (dst < src)
			while (i++ < len)
				*ch_dst++ = *ch_src++;
		else
		{
			i = len;
			while (i-- > 0)
				ch_dst[i] = ch_src[i];
		}
	}
	return (dst);
}
