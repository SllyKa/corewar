/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disassembler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 20:01:37 by bjesse            #+#    #+#             */
/*   Updated: 2020/01/16 20:01:39 by bjesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

extern t_op g_op_tab[17];

int				chk_types_byte(unsigned char opcode, unsigned char typebyte)
{
	unsigned char	arg;

	if (!(arg = typebyte_to_arg_type((typebyte >> 6) & 3))
	&& (g_op_tab[opcode - 1].argtype[0]))
		return (-1);
	if ((arg & g_op_tab[opcode - 1].argtype[0]) != arg)
		return (-1);
	if (g_op_tab[opcode - 1].argnum < 2)
		return (1);
	if (!(arg = typebyte_to_arg_type((typebyte >> 4) & 3))
	&& (g_op_tab[opcode - 1].argtype[1]))
		return (-1);
	if ((arg & g_op_tab[opcode - 1].argtype[1]) != arg)
		return (-1);
	if (g_op_tab[opcode - 1].argnum < 3)
		return (1);
	if (!(arg = typebyte_to_arg_type((typebyte >> 2) & 3))
	&& (g_op_tab[opcode - 1].argtype[2]))
		return (-1);
	if ((arg & g_op_tab[opcode - 1].argtype[2]) != arg)
		return (-1);
	return (1);
}

unsigned char	vm_core_ops_argn_type(unsigned char typebyte, size_t argn)
{
	unsigned char	var;

	var = 0;
	if (argn == 1)
		var = (typebyte >> 6) & 3;
	else if (argn == 2)
		var = (typebyte >> 4) & 3;
	else if (argn == 3)
		var = (typebyte >> 2) & 3;
	var = typebyte_to_arg_type(var);
	return (var);
}

char			*vm_readb(char *field, size_t adrs, size_t size)
{
	char			*val;
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

int				vm_btoi(unsigned char *bytes, size_t size)
{
	unsigned char	in[4];
	size_t			up;
	size_t			i;
	unsigned char	sign;

	i = 0;
	sign = (((bytes[0] >> 7 & 1) == 1) ? '\xff' : 0);
	while (i < 4)
	{
		in[i] = sign;
		i++;
	}
	i = 0;
	up = 4;
	if (size < 4)
		up = size;
	while (i < up)
	{
		in[i] = bytes[size - 1 - i];
		i++;
	}
	return (*((int*)in));
}

void			*free_vm_readb(char *bt)
{
	free(bt);
	bt = NULL;
	return (bt);
}
