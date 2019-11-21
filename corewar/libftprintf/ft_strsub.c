/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 11:39:16 by gbrandon          #+#    #+#             */
/*   Updated: 2018/11/29 15:57:57 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*new_str;
	char			*new_str_head;
	unsigned int	i;

	i = start;
	new_str = (char*)malloc(len + 1);
	if (!new_str)
		return (NULL);
	new_str_head = new_str;
	if (!s)
		return (NULL);
	while (i < len + start)
	{
		*new_str = s[i];
		new_str++;
		i++;
	}
	*new_str = '\0';
	return (new_str_head);
}
