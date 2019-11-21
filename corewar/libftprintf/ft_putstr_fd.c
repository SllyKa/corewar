/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:18:11 by lshanaha          #+#    #+#             */
/*   Updated: 2019/01/14 17:39:38 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>

void	ft_putstr_fd(char const *s, int fd)
{
	size_t		i;

	if (fd < 0)
		return ;
	i = 0;
	if (s == 0x0)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
