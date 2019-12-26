/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_core_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 11:11:17 by gbrandon          #+#    #+#             */
/*   Updated: 2019/12/26 18:11:23 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		live(t_vm *vm, t_prcs *prcs)
{
	int				uid;
	size_t			puid;

	puid = 0;
	uid = ops_read_tdir(vm->field, vm_add_address(prcs->pc, 1), DIR_SIZE);
	if (uid < 0)
		puid = uid * -1;
	prcs->livecycle = vm->cyclen;
	(vm->liven)++;
	if ((puid <= vm->players) && (puid > 0))
		cw_vm_core_upd_live(vm, uid);
}

void		ld(t_vm *vm, t_prcs *p)
{
	unsigned char	typebyte;
	unsigned char	argtype;
	int				tdir;
	int				regn;
	int				tind;

	typebyte = deref_pntr(vm->field, vm_add_address(p->pc, 1));
	argtype = vm_core_ops_argn_type(typebyte, 1);
	if (argtype == T_DIR)
	{
		tdir = ops_read_tdir(vm->field, vm_add_address(p->pc, 2), DIR_SIZE);
		p->carry = ((tdir) ? 0 : 1);
		regn = ops_read_treg(vm->field, vm_add_address(p->pc, 2 + DIR_SIZE));
		p->regs[regn - 1] = r_mov(p->regs[regn - 1], &tdir, DIR_SIZE);
	}
	else if (argtype == T_IND)
	{
		tind = ops_read_tind(vm->field, vm_add_address(p->pc, 1 + 1));
		regn = ops_read_treg(vm->field, vm_add_address(p->pc, 2 + IND_SIZE));
		tdir = ops_read_tdir(vm->field, vm_add_address(p->pc, tind),
		DIR_SIZE);
		p->carry = ((tdir) ? 0 : 1);
		p->regs[regn - 1] = r_mov(p->regs[regn - 1], &tdir, DIR_SIZE);
	}
}

void		st(t_vm *vm, t_prcs *p)
{
	unsigned char	argtype;
	int				reg;
	int				r;
	int				t;
	unsigned char	*revreg;

	argtype = deref_pntr(vm->field, vm_add_address(p->pc, 1));
	argtype = vm_core_ops_argn_type(argtype, 2);
	reg = ops_read_treg(vm->field, vm_add_address(p->pc, 1 + 1));
	if (argtype == T_REG)
	{
		r = ops_read_treg(vm->field, vm_add_address(p->pc, 2 + CODE_REG_SIZE));
		(p->regs)[r - 1] = r_mov((p->regs)[r - 1],
		p->regs[reg - 1], REG_SIZE);
	}
	else if (argtype == T_IND)
	{
		t = ops_read_tind(vm->field, vm_add_address(p->pc, 2 + CODE_REG_SIZE));
		revreg = r_get(p->regs[reg - 1]);
		reverse_reg(revreg);
		vm_writeb(vm->field, vm_add_address(p->pc, t), revreg, REG_SIZE);
		vm_vis_writeb(vm->vsfield, vm_add_address(p->pc, t),
		p->uid, REG_SIZE);
		free_rget(revreg);
	}
}

void		add(t_vm *vm, t_prcs *prcs)
{
	int				reg;
	int				a;
	int				b;

	reg = ops_read_treg(vm->field, vm_add_address(prcs->pc, 1 + 1));
	a = r_geti(prcs->regs[reg - 1]);
	reg = ops_read_treg(vm->field, vm_add_address(prcs->pc, 1 + 1 +
	CODE_REG_SIZE));
	b = r_geti(prcs->regs[reg - 1]);
	a = a + b;
	reg = ops_read_treg(vm->field, vm_add_address(prcs->pc, 1 + 1 +
	CODE_REG_SIZE + CODE_REG_SIZE));
	prcs->regs[reg - 1] = r_mov(prcs->regs[reg - 1], &a, 4);
	prcs->carry = ((a) ? 0 : 1);
}

void		sub(t_vm *vm, t_prcs *prcs)
{
	int				reg;
	int				a;
	int				b;

	reg = ops_read_treg(vm->field, vm_add_address(prcs->pc, 1 + 1));
	a = r_geti(prcs->regs[reg - 1]);
	reg = ops_read_treg(vm->field, vm_add_address(prcs->pc, 1 + 1 +
	CODE_REG_SIZE));
	b = r_geti(prcs->regs[reg - 1]);
	a = a - b;
	reg = ops_read_treg(vm->field, vm_add_address(prcs->pc, 1 + 1 +
	CODE_REG_SIZE + CODE_REG_SIZE));
	prcs->regs[reg - 1] = r_mov(prcs->regs[reg - 1], &a, 4);
	prcs->carry = ((a) ? 0 : 1);
}
