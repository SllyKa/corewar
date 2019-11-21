/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 18:24:20 by lshanaha          #+#    #+#             */
/*   Updated: 2019/01/14 17:40:29 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*res;

	res = dest;
	while (n--)
	{
		if (*src)
			*dest = *src++;
		else
			*dest = '\0';
		dest++;
	}
	return (res);
}
