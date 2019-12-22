/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_core_ops_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 21:00:48 by gbrandon          #+#    #+#             */
/*   Updated: 2019/12/22 07:12:56 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
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
*/

void			and(t_vm *vm, t_prcs *prcs)
{
	unsigned char	typebyte;
	int				val1;
	int				reg;
	int				s1;
	int				s2;

	typebyte = deref_pntr(vm->field, vm_add_address(prcs->pc, 1));
	s1 = 0;
	val1 = arrgs_chse(vm, prcs, vm_core_ops_argn_type(typebyte, 1), &s1);
	//ft_printf("VAL1: %x\n", val1);
	s2 = s1;
	val1 = (val1 & arrgs_chse(vm, prcs,
	vm_core_ops_argn_type(typebyte, 2), &s2));
	//ft_printf("VAL2: %x\n", val1);
	reg = ops_read_treg(vm->field, vm_add_address(prcs->pc, 1 + 1 + s1 + s2));
	prcs->regs[reg - 1] = r_mov(prcs->regs[reg - 1], &val1, 4);
	prcs->carry = ((val1) ? 0 : 1);
}

void			or(t_vm *vm, t_prcs *prcs)
{
	unsigned char	typebyte;
	int				val1;
	int				reg;
	int				s1;
	int				s2;

	typebyte = deref_pntr(vm->field, vm_add_address(prcs->pc, 1));
	s1 = 0;
	val1 = arrgs_chse(vm, prcs, vm_core_ops_argn_type(typebyte, 1), &s1);
	//ft_printf("VAL1: %x\n", val1);
	s2 = s1;
	val1 = (val1 | arrgs_chse(vm, prcs,
	vm_core_ops_argn_type(typebyte, 2), &s2));
	//ft_printf("VAL2: %x\n", val1);
	reg = ops_read_treg(vm->field, vm_add_address(prcs->pc, 1 + 1 + s1 + s2));
	prcs->regs[reg - 1] = r_mov(prcs->regs[reg - 1], &val1, 4);
	prcs->carry = ((val1) ? 0 : 1);
}

void			xor(t_vm *vm, t_prcs *prcs)
{
	unsigned char	typebyte;
	int				val1;
	int				reg;
	int				s1;
	int				s2;

	typebyte = deref_pntr(vm->field, vm_add_address(prcs->pc, 1));
	s1 = 0;
	val1 = arrgs_chse(vm, prcs, vm_core_ops_argn_type(typebyte, 1), &s1);
	//ft_printf("VAL1: %x\n", val1);
	s2 = s1;
	val1 = (val1 ^ arrgs_chse(vm, prcs,
	vm_core_ops_argn_type(typebyte, 2), &s2));
	//ft_printf("VAL2: %x\n", val1);
	reg = ops_read_treg(vm->field, vm_add_address(prcs->pc, 1 + 1 + s1 + s2));
	prcs->regs[reg - 1] = r_mov(prcs->regs[reg - 1], &val1, 4);
	prcs->carry = ((val1) ? 0 : 1);
}
