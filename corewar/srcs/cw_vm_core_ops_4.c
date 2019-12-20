/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_core_ops_4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 23:54:35 by gbrandon          #+#    #+#             */
/*   Updated: 2019/12/20 05:14:23 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		lldi(t_vm *vm, t_prcs *prcs)
{
	unsigned char	typebyte;
	int				val1;
	int				reg;
	int				s1;
	int				s2;

	typebyte = deref_pntr(vm->field, vm_add_address(prcs->pc, 1));
	s1 = 0;
	val1 = arrgs_chse_dirt(vm, prcs, vm_core_ops_argn_type(typebyte, 1), &s1);
	//ft_printf("VAL1: %d\n", val1);
	s2 = s1;
	val1 = (val1 + arrgs_chse_dirt(vm, prcs,
	vm_core_ops_argn_type(typebyte, 2), &s2));
	//ft_printf("VAL2: %d\n", val1);
	reg = ops_read_treg(vm->field, vm_add_address(prcs->pc, 1 + 1 + s1 + s2));
	val1 = ops_read_tdir(vm->field, vm_add_address(prcs->pc, val1), DIR_SIZE);
	prcs->carry = ((val1) ? 0 : 1);
	prcs->regs[reg - 1] = r_mov(prcs->regs[reg - 1], &val1, 4);
	//ft_printf("REG: %x\n", r_geti(prcs->regs[reg - 1]));
}

void		lfork(t_vm *vm, t_prcs *prcs)
{
	int		tdir;
	t_prcs	*pfork;

	ft_printf("LFORRK+ uid: %d\n", r_geti(prcs->regs[0]));
	tdir = ops_read_tdir(vm->field, vm_add_address(prcs->pc, 1), IND_SIZE);
	pfork = init_process_cpy(prcs,vm_add_address(prcs->pc, tdir));
	vm->prcs = add_prc(vm->prcs, pfork);
}

void		aff(t_vm *vm, t_prcs *prcs)
{
	int		reg;
	int		val;

	reg = ops_read_treg(vm->field, vm_add_address(prcs->pc, 1 + 1));
	val = r_geti(prcs->regs[reg - 1]);
	ft_printf("Aff: %c\n", val);
	//cw_vm_memdump(vm);
}