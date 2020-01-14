/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_core_check_ops.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 21:09:31 by gbrandon          #+#    #+#             */
/*   Updated: 2020/01/12 18:10:55 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

extern t_op g_op_tab[17];

unsigned char	typebyte_to_arg_type(unsigned char arg)
{
	if (arg == 0)
		return (arg);
	if (arg == REG_CODE)
		arg = T_REG;
	else if (arg == DIR_CODE)
		arg = T_DIR;
	else if (arg == IND_CODE)
		arg = T_IND;
	return (arg);
}
static int		chk_types_byte(unsigned char opcode, unsigned char typebyte)
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

char	*vm_readb(char *field, size_t adrs, size_t size)
{
	char	*val;
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

int				ops_read_treg(char *field, size_t addr)
{
	char	*treg;
	int				res;

	treg = vm_readb(field, addr, CODE_REG_SIZE);
	res = vm_btoi((unsigned char*)treg, CODE_REG_SIZE);
	free_vm_readb(treg);
	return (res);
}

static size_t	arg_type_to_size(unsigned char opcode, t_arg_type val)
{
	if (val == 0)
		return (val);
	else if ((T_REG & val) == T_REG)
		return (CODE_REG_SIZE);
	else if ((T_DIR & val) == T_DIR)
	{
		if (g_op_tab[opcode - 1].isadress)
			return (IND_SIZE);
		else
			return (DIR_SIZE);
	}
	else if ((T_IND & val) == T_IND)
		return (IND_SIZE);
	return (val);
}

int				chk_reg_valid(char *code, unsigned char opcode,
		unsigned char typebyte)
{
	int				i;
	int				tonext;
	int				reg_val;

	i = 0;
	tonext = ((g_op_tab[opcode - 1].istypeb == 0) ? 1 : 2);
	while (i < g_op_tab[opcode - 1].argnum)
	{
		if ((T_REG & vm_core_ops_argn_type(typebyte, i + 1)) == T_REG)
		{
			reg_val = ops_read_treg(code, tonext);
			if ((reg_val > REG_NUMBER) || (reg_val <= 0))
				return (-1);
			tonext += CODE_REG_SIZE;
		}
		else
			tonext += arg_type_to_size(opcode,
			vm_core_ops_argn_type(typebyte, i + 1));
		i++;
	}
	return (0);
}

int				chk_opcode(unsigned char opcode)
{
	if (opcode < 1 || opcode > 16)
		return (-1);
	return (1);
}

int				check_opsign(char *code)
{
	unsigned char		typebyte;

	typebyte = code[1];
	if (chk_opcode(code[0]) < 0)
		return (-1);
	else
	{
		if (g_op_tab[code[0] - 1].istypeb == 1 &&
		chk_types_byte(code[0], typebyte) < 0)
			return (-1);
		else
		{
			if (g_op_tab[code[0] - 1].istypeb == 1 &&
			chk_reg_valid(code, code[0], typebyte) < 0)
				return (-1);
			else
				return (1);
		}
	}
	return (-1);
}
