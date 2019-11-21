/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 20:43:04 by lshanaha          #+#    #+#             */
/*   Updated: 2019/01/24 16:20:50 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*arr;
	size_t	i;

	i = 0;
	if (size > size + 1)
		return (NULL);
	arr = (char *)malloc(size + 1);
	if (arr == NULL)
		return (NULL);
	while (i <= size)
		arr[i++] = 0;
	return (arr);
}
