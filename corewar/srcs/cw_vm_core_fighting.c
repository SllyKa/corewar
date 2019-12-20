/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_core_fighting.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 15:28:42 by gbrandon          #+#    #+#             */
/*   Updated: 2019/12/20 05:26:07 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern t_op g_op_tab[17];

static void	read_operation(unsigned char *field, t_prcs *prc)
{
	prc->curop = deref_pntr(field, prc->pc);
	if (chk_opcode(prc->curop) > 0)
		prc->waitcycle = g_op_tab[prc->curop - 1].wait;
	else
		prc->waitcycle = 0;
	// just testing
	//ft_printf("uid: %d\n", r_geti(prc->regs[0]));
	//ft_printf("cur_pos: %i\n", prc->pc);
	//ft_printf("code: %.2x\n", prc->curop);
}

static void	exec_ops(t_vm *vm, t_prcs *prcs)
{
	void				(*f_ptr)(t_vm *vm, t_prcs *pr);
	unsigned char		typebyte;

	typebyte = deref_pntr(vm->field, vm_add_address(prcs->pc, 1));
	f_ptr = g_op_tab[prcs->curop - 1].f_ptr;
	f_ptr(vm, prcs);
	if (prcs->curop == 1)
		prcs->pc = vm_add_address(prcs->pc, 1 + DIR_SIZE);
	else if (prcs->curop == 9)
	{
		if (!prcs->carry)
			prcs->pc = vm_add_address(prcs->pc, 1 + IND_SIZE);
	}
	else if ((prcs->curop == 12) || (prcs->curop == 15))
		prcs->pc = vm_add_address(prcs->pc, 1 + IND_SIZE);
	else
		prcs->pc = vm_add_address(prcs->pc, 1 + pass_bytes(typebyte));	
}

static void	prcs_cycle(t_vm *vm, t_prcs *prcs)
{
	while (prcs)
	{
		if (prcs->waitcycle == 0)
			read_operation(vm->field, prcs);
		if (prcs->waitcycle > 0)
			(prcs->waitcycle)--;
		if (prcs->waitcycle == 0)
		{
			if (check_opsign(vm, prcs) > 0)
				exec_ops(vm, prcs);
		}
		prcs = prcs->next;
	}
}

static void	cw_vm_check(t_vm *vm)
{
	t_prcs		*prcs;
	t_prcs		*prev;

	prcs = vm->prcs;
	prev = NULL;
	while(prcs)
	{
		if (prcs->livecycle < (int)(vm->cyclen - vm->cycles_to_die))
		{
			ft_printf("out_uid: %d\n", r_geti(prcs->regs[0]));
			prcs = cw_del_prcs(vm, prcs, prev);
		}
		else
		{
			prev = prcs;
			prcs = prcs->next;
		}
	}
	if (vm->liven >= NBR_LIVE)
	{
		vm->cycles_to_die -= CYCLE_DELTA;
		vm->checkn = 1;
	}
	else
		(vm->checkn)++;
	if (vm->checkn == MAX_CHECKS)
	{
		vm->cycles_to_die -= CYCLE_DELTA;
		vm->checkn = 1;
	}
	ft_printf("cyclen: %d\n", vm->cyclen);
	ft_printf("cycles_to_die: %d\n", vm->cycles_to_die);
	ft_printf("checkN: %d\n", vm->checkn);
	ft_printf("liven: %d\n", vm->liven);
	ft_printf("LAST_LIIIIIVE: %d\n", vm->lastlive);
	vm->liven = 0;
}

int			cw_fight(t_vm *vm)
{
	int			i;
	t_prcs		*prcs_head;

	i = 0;
	while(vm->prcs)
	{
		i = 0;
		while(i < vm->cycles_to_die)
		{
			prcs_head = vm->prcs;
			prcs_cycle(vm, prcs_head);
			i++;
			(vm->cyclen)++;
		}
		cw_vm_check(vm);
	}
	return (0);
}