/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 14:10:57 by lshanaha          #+#    #+#             */
/*   Updated: 2019/01/14 17:40:24 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strncat(char *destination, const char *append, size_t n)
{
	char	*res;

	res = destination;
	while (*destination)
		destination++;
	while (*append && n--)
		*destination++ = *append++;
	*destination = '\0';
	return (res);
}
