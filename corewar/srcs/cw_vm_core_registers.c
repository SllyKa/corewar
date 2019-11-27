/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_core_registers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 16:36:06 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/27 17:02:06 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char	*r_mov(char *reg, void *data, size_t size)
{
	int		st;

	st = REG_SIZE - size;
	if (st = 0)
		reg = ft_memcpy(reg, data, size);
	else if (st > 0)
		reg = ft_memcpy(reg[st - 1], data, size);
	else if (st < 0)
	{
		st *= -1;
		reg = ft_memcpy(reg, data + (st - 1), st);
	}
	return (reg);
}