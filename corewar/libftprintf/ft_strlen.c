/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 20:20:07 by gbrandon          #+#    #+#             */
/*   Updated: 2018/11/24 18:49:36 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t		ft_strlen(const char *str)
{
	const char		*beg;

	beg = str;
	while (*str)
	{
		str++;
	}
	return ((size_t)(str - beg));
}
