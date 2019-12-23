/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_core_ops_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 21:00:48 by gbrandon          #+#    #+#             */
/*   Updated: 2019/12/24 01:57:18 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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
	s2 = s1;
	val1 = (val1 & arrgs_chse(vm, prcs,
	vm_core_ops_argn_type(typebyte, 2), &s2));
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
	s2 = s1;
	val1 = (val1 | arrgs_chse(vm, prcs,
	vm_core_ops_argn_type(typebyte, 2), &s2));
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
	s2 = s1;
	val1 = (val1 ^ arrgs_chse(vm, prcs,
	vm_core_ops_argn_type(typebyte, 2), &s2));
	reg = ops_read_treg(vm->field, vm_add_address(prcs->pc, 1 + 1 + s1 + s2));
	prcs->regs[reg - 1] = r_mov(prcs->regs[reg - 1], &val1, 4);
	prcs->carry = ((val1) ? 0 : 1);
}
