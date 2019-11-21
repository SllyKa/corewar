/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 20:09:13 by lshanaha          #+#    #+#             */
/*   Updated: 2019/01/14 17:39:49 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strchr(const char *str, int ch)
{
	char byte;

	byte = (char)(ch);
	while (*str != byte)
		if (!*str++)
			return (0);
	return ((char *)str);
}
