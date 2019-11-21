/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 20:13:35 by lshanaha          #+#    #+#             */
/*   Updated: 2019/01/14 17:40:50 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strrchr(const char *s, int c)
{
	char		byte;
	const char	*result;

	result = NULL;
	byte = (char)(c % 256);
	while (*s)
	{
		if (*s == byte)
			result = s;
		s++;
	}
	if (*s == byte)
		result = s;
	return ((char *)result);
}
