/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_core_rwbytes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 12:50:38 by gbrandon          #+#    #+#             */
/*   Updated: 2019/12/17 19:40:51 by gbrandon         ###   ########.fr       */
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
		val = ft_memcpy(val + (size - delsize), field, delsize);
	}
	return (val);
}

void			*free_vm_readb(unsigned char *bt)
{
	free(bt);
	bt = NULL;
	return (bt);
}
