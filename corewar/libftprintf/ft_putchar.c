/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 16:38:07 by lshanaha          #+#    #+#             */
/*   Updated: 2019/01/14 17:39:00 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>

void	ft_putchar(char c)
{
	unsigned char q;
	unsigned char z;

	if (c < 0)
	{
		q = 256 + c;
		z = q;
		q = q & 0xbf;
		z = (((z >> 6) & 0x1f) | (0xc0));
		write(1, &z, 1);
		write(1, &q, 1);
	}
	else
		write(1, &c, 1);
}
