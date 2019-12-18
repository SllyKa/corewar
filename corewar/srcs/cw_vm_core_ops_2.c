/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_core_ops_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 21:00:48 by gbrandon          #+#    #+#             */
/*   Updated: 2019/12/18 22:09:18 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static unsigned char	*arrgs_chse(t_vm *vm, t_prcs *prcs,
unsigned char argtype, int *size)
{
	int				reg;
	unsigned char	*val;

	if (argtype == T_REG)
	{
		reg = ops_read_treg(vm->field, vm_add_address(prcs->pc, 1 + 1 + *size));
		val = r_get(prcs->regs[reg - 1]);
		*size = REG_SIZE;
	}
	else if (argtype = T_DIR)
	{
		val = vm_readb(vm->field, vm_add_address(prcs->pc, 1 + 1 + *size), DIR_SIZE);
		*size = DIR_SIZE;
	}
	else if (argtype == T_IND)
	{
		val = vm_readb(vm->field, vm_add_address(prcs->pc, 1 + 1 + *size), IND_SIZE);
		*size = IND_SIZE;
	}
	return (val);
}

void		and(t_vm *vm, t_prcs *prcs)
{
	unsigned char	argtype;
	unsigned char	*val;
	unsigned char	*val2;
	int				size1;
	int				size2;

	argtype = deref_pntr(vm->field, vm_add_address(prcs->pc, 1));
	argtype = vm_core_ops_argn_type(argtype, 1);
	size1 = 0;
	val = arrgs_chse(vm, prcs, argtype, &size1);
	argtype = vm_core_ops_argn_type(argtype, 2);
	size2 = size1;
	val2 = arrgs_chse(vm, prcs, argtype, &size1);
	val = vm_core_add(val, val2, size1, &size2);
	size1 = ops_read_treg(vm->field, 1 + 1 + size1 + size2);
	prcs->regs[size1 - 1] = r_mov(prcs->regs[size1 - 1], val, size2);

	//redesign all here!
}