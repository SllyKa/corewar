/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_core_registers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 16:36:06 by gbrandon          #+#    #+#             */
/*   Updated: 2019/12/04 18:44:31 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char	*r_mov(char *reg, void *data, size_t size)
{
	int		st;

	st = REG_SIZE - size;
	ft_bzero(reg, REG_SIZE);
	if (st == 0)
		reg = ft_memcpy(reg, data, size);
	else if (st > 0)
		reg = ft_memcpy(&(reg[st - 1]), data, size);
	else if (st < 0)
	{
		st *= -1;
		reg = ft_memcpy(reg, data + (st - 1), st);
	}
	return (reg);
}

unsigned char	*r_get(char *reg)
{
	unsigned char	*res;

	res = ft_memalloc(REG_SIZE + 1);
	res = ft_memcpy(res, reg, REG_SIZE);
	return (res);
}

void	*free_rget(unsigned char *val)
{
	free(val);
	val = NULL;
	return (val);
}

int		r_geti(char *reg)
{
	// do not use REG_SIZE variable (!)
	int num;

	num = *(int *)reg;
	return (num);
}