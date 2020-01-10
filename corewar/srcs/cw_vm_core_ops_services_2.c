/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_core_ops_services_2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 21:02:32 by gbrandon          #+#    #+#             */
/*   Updated: 2020/01/10 08:21:00 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		lld_bytesw_count(t_vm *vm, t_prcs *prcs, size_t cnt)
{
	int		val;
	int		reg;

	val = ops_read_tdir(vm->field, vm_add_address(prcs->pc, 2), IND_SIZE);
	reg = ops_read_treg(vm->field, vm_add_address(prcs->pc, 2 + IND_SIZE));
	if (cnt == 2)
	{
		val = ops_read_tdir(vm->field, vm_add_address(prcs->pc, val),
		IND_SIZE);
		prcs->carry = ((val) ? 0 : 1);
		(prcs->regs)[reg - 1] = r_mov((prcs->regs)[reg - 1], ((char*)&val),
		IND_SIZE);
	}
	else
	{
		val = ops_read_tdir(vm->field, vm_add_address(prcs->pc, val),
		DIR_SIZE);
		prcs->carry = ((val) ? 0 : 1);
		(prcs->regs)[reg - 1] = r_mov((prcs->regs)[reg - 1], &val, DIR_SIZE);
	}
}
