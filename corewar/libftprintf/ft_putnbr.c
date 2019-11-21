/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 11:35:30 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/12 11:10:58 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		rec(int n)
{
	if (n / 10 == 0)
	{
		ft_putchar(n + 48);
	}
	else
	{
		rec(n / 10);
		ft_putchar((n % 10) + 48);
	}
}

void			ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putchar('-');
		rec(n / -10);
		ft_putchar('8');
	}
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n *= -1;
		}
		rec(n);
	}
}
