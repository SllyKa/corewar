/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_core_ops_services.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 14:59:40 by gbrandon          #+#    #+#             */
/*   Updated: 2019/12/24 02:21:29 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		plrs_lives_upd(t_plr_ardata *plrdata, int uid)
{
	t_plr_ardata	*pl;

	pl = plrdata;
	while (pl)
	{
		if ((pl->uid * -1) == uid)
		{
			(pl->liven)++;
			cw_vm_flags_verb_live(plrdata);
		}
		pl = pl->next;
	}
}

void			cw_vm_core_upd_live(t_vm *vm, int uid)
{
	vm->lastlive = uid;
	plrs_lives_upd(vm->plrdata, uid);
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

int				arrgs_chse(t_vm *vm, t_prcs *prcs,
unsigned char argtype, int *s)
{
	int				reg;
	int				val;

	val = 0;
	if (argtype == T_REG)
	{
		reg = ops_read_treg(vm->field, vm_add_address(prcs->pc, 1 + 1 + *s));
		val = r_geti(prcs->regs[reg - 1]);
		*s = CODE_REG_SIZE;
	}
	else if (argtype == T_DIR)
	{
		val = ops_read_tdir(vm->field,
		vm_add_address(prcs->pc, 1 + 1 + *s), DIR_SIZE);
		*s = DIR_SIZE;
	}
	else if (argtype == T_IND)
	{
		val = ops_read_tind(vm->field, vm_add_address(prcs->pc, 1 + 1 + *s));
		*s = IND_SIZE;
		val = ops_read_tdir(vm->field,
		vm_add_address(prcs->pc, val), DIR_SIZE);
	}
	return (val);
}

int				arrgs_chse_dirt(t_vm *vm, t_prcs *prcs,
unsigned char argtype, int *s)
{
	int				reg;
	int				val;

	val = 0;
	if (argtype == T_REG)
	{
		reg = ops_read_treg(vm->field, vm_add_address(prcs->pc, 1 + 1 + *s));
		val = r_geti(prcs->regs[reg - 1]);
		*s = CODE_REG_SIZE;
	}
	else if (argtype == T_DIR)
	{
		val = ops_read_tdir(vm->field,
		vm_add_address(prcs->pc, 1 + 1 + *s), IND_SIZE);
		*s = IND_SIZE;
	}
	else if (argtype == T_IND)
	{
		val = ops_read_tind(vm->field, vm_add_address(prcs->pc, 1 + 1 + *s));
		*s = IND_SIZE;
		val = ops_read_tdir(vm->field,
		vm_add_address(prcs->pc, val), DIR_SIZE);
	}
	return (val);
}
