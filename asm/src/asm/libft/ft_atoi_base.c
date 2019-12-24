/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 16:15:40 by fsinged           #+#    #+#             */
/*   Updated: 2019/11/22 13:23:59 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uintmax_t		ft_atoi_base(char *str, int base)
{
	size_t		i;
	size_t		max_base;
	uintmax_t	num;

	i = 0;
	max_base = 1;
	num = 0;
	while (str[++i])
		max_base *= base;
	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			num += max_base * (str[i] - '0');
		else
			num += max_base * (ft_tolower(str[i]) - 'a');
		i++;
		max_base /= base;
	}
	return (num);
}
