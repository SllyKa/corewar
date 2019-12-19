/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_core_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 11:11:17 by gbrandon          #+#    #+#             */
/*   Updated: 2019/12/20 01:51:32 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		live(t_vm *vm, t_prcs *prcs)
{
	unsigned char	*tdir;
	int				uid;
	int				r1;

	uid = ops_read_tdir(vm->field, vm_add_address(prcs->pc, 1), DIR_SIZE);
	tdir = r_get(prcs->regs[0]);
	r1 = *((int*)tdir);
	tdir = free_rget(tdir);
	prcs->livecycle = vm->cyclen;
	if (uid == r1)
		cw_vm_core_upd_live(vm, r1);
}

void		ld(t_vm *vm, t_prcs *prcs)
{
	unsigned char	typebyte;
	unsigned char	argtype;
	int				tdir;
	int				regn;
	int				tind;

	typebyte = deref_pntr(vm->field, vm_add_address(prcs->pc, 1));
	argtype = vm_core_ops_argn_type(typebyte, 1);
	if (argtype == T_DIR)
	{
		tdir = ops_read_tdir(vm->field, vm_add_address(prcs->pc, 1 + 1), DIR_SIZE);
		prcs->carry = ((tdir) ? 0 : 1);
		regn = ops_read_treg(vm->field, vm_add_address(prcs->pc, 1 + 1 + DIR_SIZE));
		(prcs->regs)[regn - 1] = r_mov((prcs->regs)[regn - 1], &tdir, DIR_SIZE);
	}
	else if (argtype == T_IND)
	{
		tind = ops_read_tind(vm->field, vm_add_address(prcs->pc, 1 + 1));
		regn = ops_read_treg(vm->field, vm_add_address(prcs->pc, 1 + 1 + IND_SIZE));
		tdir = ops_read_tdir(vm->field, vm_add_address(prcs->pc, tind), DIR_SIZE);
		prcs->carry = ((tdir) ? 0 : 1);
		(prcs->regs)[regn - 1] = r_mov((prcs->regs)[regn - 1], &tdir, DIR_SIZE);
	}
}

void		st(t_vm *vm, t_prcs *prcs)
{
	unsigned char	argtype;
	int				reg;
	int				reg2;
	int				tind;
	unsigned char	*revreg;

	argtype = deref_pntr(vm->field, vm_add_address(prcs->pc, 1));
	argtype = vm_core_ops_argn_type(argtype, 2);
	reg = ops_read_treg(vm->field, vm_add_address(prcs->pc, 1 + 1));
	if (argtype == T_REG)
	{
		//ft_printf("reg_1: %d\n", reg);
		reg2 = ops_read_treg(vm->field, vm_add_address(prcs->pc, 1 + 1 +
		CODE_REG_SIZE));
		//ft_printf("reg_2: %d\n", reg2);
		(prcs->regs)[reg2 - 1] = r_mov((prcs->regs)[reg2 - 1],
		prcs->regs[reg - 1], REG_SIZE);
		//ft_printf("reg_1_value: %d\n", r_geti(prcs->regs[reg - 1]));
		//ft_printf("reg_2_value: %d\n", r_geti(prcs->regs[reg2 - 1]));
	}
	else if (argtype == T_IND)
	{
		tind = ops_read_tind(vm->field, vm_add_address(prcs->pc, 1 + 1 +
		CODE_REG_SIZE));
		//ft_printf("T_IND: %d\n", tind);
		//ft_printf("CUR_POS: %d\n", prcs->pc);
		//ft_printf("NEW_POS: %d\n", vm_add_address(prcs->pc, tind));
		revreg = r_get(prcs->regs[reg - 1]);
		reverse_reg(revreg);
		vm_writeb(vm->field, vm_add_address(prcs->pc, tind), revreg, REG_SIZE);
		free_rget(revreg);
	}
}

void		add(t_vm *vm, t_prcs *prcs)
{
	int				reg;
	int				a;
	int				b;

	reg = ops_read_treg(vm->field, vm_add_address(prcs->pc, 1 + 1));
	//ft_printf("01_VAL: %d\n", r_geti(prcs->regs[reg - 1]));
	a = r_geti(prcs->regs[reg - 1]);
	reg = ops_read_treg(vm->field, vm_add_address(prcs->pc, 1 + 1 +
	CODE_REG_SIZE));
	//ft_printf("02_VAL: %d\n", r_geti(prcs->regs[reg - 1]));
	b = r_geti(prcs->regs[reg - 1]);
	a = a + b;
	reg = ops_read_treg(vm->field, vm_add_address(prcs->pc, 1 + 1 +
	CODE_REG_SIZE + CODE_REG_SIZE));
	prcs->regs[reg - 1] = r_mov(prcs->regs[reg - 1], &a, 4);
	//ft_printf("03_VAL: %d\n", r_geti(prcs->regs[reg - 1]));
	prcs->carry = ((a) ? 0 : 1);
}

void		sub(t_vm *vm, t_prcs *prcs)
{
	int				reg;
	int				a;
	int				b;

	reg = ops_read_treg(vm->field, vm_add_address(prcs->pc, 1 + 1));
	//ft_printf("01_VAL: %d\n", r_geti(prcs->regs[reg - 1]));
	a = r_geti(prcs->regs[reg - 1]);
	reg = ops_read_treg(vm->field, vm_add_address(prcs->pc, 1 + 1 +
	CODE_REG_SIZE));
	//ft_printf("02_VAL: %d\n", r_geti(prcs->regs[reg - 1]));
	b = r_geti(prcs->regs[reg - 1]);
	a = a - b;
	reg = ops_read_treg(vm->field, vm_add_address(prcs->pc, 1 + 1 +
	CODE_REG_SIZE + CODE_REG_SIZE));
	prcs->regs[reg - 1] = r_mov(prcs->regs[reg - 1], &a, 4);
	//ft_printf("03_VAL: %d\n", r_geti(prcs->regs[reg - 1]));
	prcs->carry = ((a) ? 0 : 1);
}