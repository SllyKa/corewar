/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:22:29 by lshanaha          #+#    #+#             */
/*   Updated: 2019/01/14 17:38:48 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char			*arr;
	unsigned char	byte;
	size_t			i;

	arr = (char *)s;
	byte = (unsigned char)c;
	i = 0;
	while (i < n)
		arr[i++] = byte;
	return (s);
}
