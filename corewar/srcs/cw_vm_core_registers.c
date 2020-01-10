/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_core_registers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 16:36:06 by gbrandon          #+#    #+#             */
/*   Updated: 2020/01/10 08:21:14 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char			*r_mov(char *reg, void *data, size_t size)
{
	int				st;
	unsigned char	sign;
	size_t			i;

	i = 0;
	st = REG_SIZE - size;
	if (reg == data)
		return (data);
	sign = (((((char*)data)[3] >> 7 & 1) == 1) ? '\xff' : 0);
	while (i < REG_SIZE)
	{
		reg[i] = sign;
		i++;
	}
	if (st == 0)
		reg = ft_memcpy(reg, data, size);
	else if (st > 0)
		ft_memcpy(reg, data, size);
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

	if (REG_SIZE < 4)
		res = ft_memalloc(4 + 1);
	else
		res = ft_memalloc(REG_SIZE + 1);
	res = ft_memcpy(res, reg, REG_SIZE);
	return (res);
}

void			*free_rget(unsigned char *val)
{
	free(val);
	val = NULL;
	return (val);
}

void			reverse_reg(unsigned char *reg)
{
	size_t	i;
	char	tmp;

	i = 0;
	while (i < REG_SIZE / 2)
	{
		tmp = reg[i];
		reg[i] = reg[REG_SIZE - 1 - i];
		reg[REG_SIZE - 1 - i] = tmp;
		i++;
	}
}

int				r_geti(char *reg)
{
	int				num;
	unsigned char	*r;

	r = r_get(reg);
	num = *(int *)r;
	r = free_rget(r);
	return (num);
}
