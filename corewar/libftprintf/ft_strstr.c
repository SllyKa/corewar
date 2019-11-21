/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:56:05 by lshanaha          #+#    #+#             */
/*   Updated: 2019/01/14 17:40:59 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strstr(const char *str, const char *sub)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		if (str[i] == sub[0])
		{
			j = 0;
			while (sub[j] && (str[i + j] == sub[j]))
				j++;
			if (!sub[j])
				return ((char *)(str + i));
		}
		i++;
	}
	if (*sub)
		return (NULL);
	else
		return ((char *)str);
}
