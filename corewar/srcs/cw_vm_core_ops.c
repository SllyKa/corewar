/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_core_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 11:11:17 by gbrandon          #+#    #+#             */
/*   Updated: 2019/12/17 23:55:52 by gbrandon         ###   ########.fr       */
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
	size_t			tind;

	typebyte = deref_pntr(vm->field, vm_add_address(prcs->pc, 1));
	argtype = vm_core_ops_argn_type(typebyte, 1);
	if (argtype == T_DIR)
	{
		tdir = ops_read_tdir(vm->field, vm_add_address(prcs->pc, 1 + 1), DIR_SIZE);
		regn = ops_read_treg(vm->field, vm_add_address(prcs->pc, 1 + 1 + DIR_SIZE));
		(prcs->regs)[regn] = r_mov((prcs->regs)[regn], &tdir, DIR_SIZE);
	}
	else if (argtype == T_IND)
	{
		tind = ops_read_tind(vm->field, vm_add_address(prcs->pc, 1 + 1));
		regn = ops_read_treg(vm->field, vm_add_address(prcs->pc, 1 + 1 + IND_SIZE));
		tdir = ops_read_tdir(vm->field, vm_add_address(prcs->pc, tind), DIR_SIZE);
		(prcs->regs)[regn] = r_mov((prcs->regs)[regn], &tdir, DIR_SIZE);
		ft_printf("VALUE: %x\n", r_geti(prcs->regs[regn]));
	}
}