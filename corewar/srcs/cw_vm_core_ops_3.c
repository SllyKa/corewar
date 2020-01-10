/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_core_ops_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 17:25:01 by gbrandon          #+#    #+#             */
/*   Updated: 2020/01/10 08:20:14 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern int	g_flags;

void		zjmp(t_vm *vm, t_prcs *prcs)
{
	int		offset;

	if (prcs->carry)
	{
		offset = ops_read_tdir(vm->field, vm_add_address(prcs->pc, 1),
		IND_SIZE);
		prcs->pc = vm_add_address(prcs->pc, offset % IDX_MOD);
	}
}

void		ldi(t_vm *vm, t_prcs *prcs)
{
	unsigned char	typebyte;
	int				val1;
	int				reg;
	int				s1;
	int				s2;

	typebyte = deref_pntr(vm->field, vm_add_address(prcs->pc, 1));
	s1 = 0;
	val1 = arrgs_chse_dirt(vm, prcs, vm_core_ops_argn_type(typebyte, 1), &s1);
	s2 = s1;
	val1 = (val1 + arrgs_chse_dirt(vm, prcs,
	vm_core_ops_argn_type(typebyte, 2), &s2)) % IDX_MOD;
	reg = ops_read_treg(vm->field, vm_add_address(prcs->pc, 1 + 1 + s1 + s2));
	val1 = ops_read_tdir(vm->field, vm_add_address(prcs->pc, val1), DIR_SIZE);
	prcs->regs[reg - 1] = r_mov(prcs->regs[reg - 1], &val1, 4);
}

void		sti(t_vm *vm, t_prcs *prcs)
{
	unsigned char	typebyte;
	int				val1;
	int				reg;
	int				s1;
	int				s2;

	typebyte = deref_pntr(vm->field, vm_add_address(prcs->pc, 1));
	s1 = CODE_REG_SIZE;
	reg = ops_read_treg(vm->field, vm_add_address(prcs->pc, 1 + 1));
	//ft_printf("reg_num: %d\n", reg);
	//ft_printf("reg: %x\n", r_geti(prcs->regs[reg - 1]));
	val1 = arrgs_chse_dirt(vm, prcs, vm_core_ops_argn_type(typebyte, 2), &s1);
	//ft_printf("val1: %d\n", val1);
	s2 = s1 + CODE_REG_SIZE;
	val1 = (val1 + arrgs_chse_dirt(vm, prcs,
	vm_core_ops_argn_type(typebyte, 3), &s2)) % IDX_MOD;
	//ft_printf("val2: %d\n", val1);
	//ft_printf("pc: %d\n", prcs->pc);	
	//ft_printf("general: %d\n", vm_add_address(prcs->pc, val1));	
	vm_writebreg(vm->field, vm_add_address(prcs->pc, val1),
	prcs->regs[reg - 1], REG_SIZE);
	vm_vis_writeb(vm->vsfield, vm_add_address(prcs->pc, val1),
	prcs->uid, REG_SIZE);
}

void		vm_fork(t_vm *vm, t_prcs *prcs)
{
	int		tdir;
	t_prcs	*pfork;

	tdir = ops_read_tdir(vm->field, vm_add_address(prcs->pc, 1), IND_SIZE);
	tdir = tdir % IDX_MOD;
	pfork = init_process_cpy(prcs, vm_add_address(prcs->pc, tdir));
	vm->prcs = add_prc(vm->prcs, pfork);
}

void		lld(t_vm *vm, t_prcs *prcs)
{
	unsigned char	argtype;
	int				val;
	int				reg;

	argtype = deref_pntr(vm->field, vm_add_address(prcs->pc, 1));
	argtype = vm_core_ops_argn_type(argtype, 1);
	if (argtype == T_DIR)
	{
		val = ops_read_tdir(vm->field, vm_add_address(prcs->pc, 2), DIR_SIZE);
		prcs->carry = ((val) ? 0 : 1);
		reg = ops_read_treg(vm->field, vm_add_address(prcs->pc, 2 + DIR_SIZE));
		(prcs->regs)[reg - 1] = r_mov((prcs->regs)[reg - 1], &val,
		DIR_SIZE);
	}
	else if (argtype == T_IND)
	{
		if ((4 & g_flags) == 4)
			lld_bytesw_count(vm, prcs, 2);
		else
			lld_bytesw_count(vm, prcs, 4);
	}
}
