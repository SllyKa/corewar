/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_core_rwbytes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 12:50:38 by gbrandon          #+#    #+#             */
/*   Updated: 2019/12/26 22:53:20 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned char	*vm_readb(unsigned char *field, size_t adrs, size_t size)
{
	unsigned char	*val;
	size_t			delsize;

	val = ft_memalloc(size + 1);
	if ((adrs + size) <= MEM_SIZE)
		val = ft_memcpy(val, field + adrs, size);
	else
	{
		delsize = (adrs + size) - MEM_SIZE;
		val = ft_memcpy(val, field + adrs, size - delsize);
		ft_memcpy(val + (size - delsize), field, delsize);
	}
	return (val);
}

void			vm_writeb(unsigned char *field, size_t adrs,
void *data, size_t size)
{
	size_t		delsize;

	if ((adrs + size) <= MEM_SIZE)
		ft_memcpy(field + adrs, data, size);
	else
	{
		delsize = (adrs + size) - MEM_SIZE;
		ft_memcpy(field + adrs, data, size - delsize);
		ft_memcpy(field, data + (size - delsize), delsize);
	}
}

void			vm_vis_writeb(unsigned char *field, size_t adrs,
int plrnum, size_t size)
{
	size_t		delsize;

	if ((adrs + size) <= MEM_SIZE)
		ft_memset(field + adrs, plrnum, size);
	else
	{
		delsize = (adrs + size) - MEM_SIZE;
		ft_memset(field + adrs, plrnum, size - delsize);
		ft_memset(field, plrnum, delsize);
	}
}

void			vm_writebreg(unsigned char *field, size_t adrs,
void *reg, size_t size)
{
	unsigned char	*bytes;

	bytes = r_get(reg);
	reverse_reg(bytes);
	vm_writeb(field, adrs, bytes, size);
	free_rget(bytes);
}

void			*free_vm_readb(unsigned char *bt)
{
	free(bt);
	bt = NULL;
	return (bt);
}
