/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_core_fighting.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 15:28:42 by gbrandon          #+#    #+#             */
/*   Updated: 2019/12/27 17:44:49 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern t_op	g_op_tab[17];
extern int	g_memdmp;
extern char	g_flags;

static void	read_operation(unsigned char *field, t_prcs *prc)
{
	prc->curop = deref_pntr(field, prc->pc);
	if (chk_opcode(prc->curop) > 0)
		prc->waitcycle = g_op_tab[prc->curop - 1].wait;
	else
		prc->waitcycle = 0;
	cw_vm_flags_verb_unitpos(prc);
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
		prcs->pc = vm_add_address(prcs->pc, 1 + pass_bytes(typebyte, prcs));
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
	while (prcs)
	{
		if (prcs->livecycle <= (int)(vm->cyclen - vm->cycles_to_die))
		{
			cw_vm_flags_verb_deaths(prcs, vm);
			prcs = cw_del_prcs(vm, prcs, prev);
		}
		else
		{
			prev = prcs;
			prcs = prcs->next;
		}
	}
	cw_vm_cycle_set(vm);
	cw_vm_flags_verb_detcycle(vm);
}

int			cw_fight(t_vm *vm)
{
	int			i;
	t_prcs		*prcs_head;

	while (vm->prcs)
	{
		i = 0;
		if (vm->cycles_to_die < 0)
			i = vm->cycles_to_die - 1;
		while (i < vm->cycles_to_die)
		{
			prcs_head = vm->prcs;
			prcs_cycle(vm, prcs_head);
			i++;
			(vm->cyclen)++;
			cw_vm_flags_verb_cycle(vm);
			if ((2 & g_flags) == 2)
				cw_vs_print_frame(vm);
			if (!cw_vm_chk_memdump(vm))
				return (0);
		}
		cw_vm_check(vm);
	}
	return (0);
}
