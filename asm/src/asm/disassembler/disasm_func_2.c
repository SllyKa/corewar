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

int				ops_read_tind(char *field, size_t addr)
{
	char			*tind;
	int				resoffst;

	tind = vm_readb(field, addr, IND_SIZE);
	resoffst = vm_btoi((unsigned char*)tind, IND_SIZE);
	free_vm_readb(tind);
	return (resoffst);
}

int				ops_read_treg(char *field, size_t addr)
{
	char			*treg;
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

int				ops_read_tdir(char *field, size_t addr, size_t size)
{
	char			*tdir;
	int				res;

	tdir = vm_readb(field, addr, size);
	res = vm_btoi((unsigned char*)tdir, size);
	tdir = free_vm_readb(tdir);
	return (res);
}
