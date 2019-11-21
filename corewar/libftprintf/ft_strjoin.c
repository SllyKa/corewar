/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 12:25:59 by gbrandon          #+#    #+#             */
/*   Updated: 2018/11/29 13:11:57 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	len;

	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		new_str = (char*)malloc(len + 1);
		if (!new_str)
			return (NULL);
		*new_str = '\0';
		new_str = ft_strcat(new_str, s1);
		new_str = ft_strcat(new_str, s2);
		new_str[len] = '\0';
		return (new_str);
	}
	return (NULL);
}
