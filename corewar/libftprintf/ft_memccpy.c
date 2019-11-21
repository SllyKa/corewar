/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:15:11 by gbrandon          #+#    #+#             */
/*   Updated: 2018/11/28 10:11:30 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*char_dst;
	unsigned char		*char_src;

	i = 0;
	char_dst = (unsigned char*)dst;
	char_src = (unsigned char*)src;
	while (i < n)
	{
		*char_dst = *char_src;
		if (*char_dst == (unsigned char)c)
		{
			return (char_dst + 1);
		}
		char_dst++;
		char_src++;
		i++;
	}
	return (NULL);
}
