/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:00:56 by gbrandon          #+#    #+#             */
/*   Updated: 2018/12/06 11:06:32 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *dest, int c, size_t len)
{
	unsigned char	uc;
	size_t			i;
	char			*dest_al;

	uc = (unsigned char)c;
	i = 0;
	dest_al = (char*)dest;
	while (i < len)
	{
		*dest_al = uc;
		i++;
		dest_al++;
	}
	return (dest);
}
