/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:45:30 by lshanaha          #+#    #+#             */
/*   Updated: 2019/01/14 17:37:33 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*temp;

	if (n == 0)
		return ;
	temp = (char *)s;
	i = 0;
	while (i < n)
		temp[i++] = 0;
}
