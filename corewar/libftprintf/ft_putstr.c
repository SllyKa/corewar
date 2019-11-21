/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:53:00 by lshanaha          #+#    #+#             */
/*   Updated: 2019/01/14 17:39:42 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>

void	ft_putstr(char const *s)
{
	size_t		i;

	i = 0;
	if (s == 0x0)
		return ;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}
