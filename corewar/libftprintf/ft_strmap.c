/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:10:13 by lshanaha          #+#    #+#             */
/*   Updated: 2019/01/14 17:40:19 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new_str;
	size_t	i;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	new_str = (char *)malloc(ft_strlen(s) + 1);
	if (new_str == NULL)
		return (NULL);
	while (s[i])
	{
		if (!(new_str[i] = (*f)(s[i])))
			return (NULL);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
