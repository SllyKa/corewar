/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_core_fighting.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 15:28:42 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/29 21:51:12 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern t_op op_tab[17];

static void	read_operation(unsigned char *field, t_prcs *prc)
{
	prc->curop = deref_pntr(field, prc->pc);
	if (prc->curop >= 1 && prc->curop <= 16)
		prc->waitcycle = op_tab[prc->curop].wait;
	else
		prc->waitcycle = 0;
	ft_printf("uid: %d\n", r_geti(prc->regs[0]));
	ft_printf("cur_pos: %i\n", prc->pc);
	ft_printf("code: %.2x\n", prc->curop);
}

int			cw_fight(t_vm *vm)
{
	int			i;
	t_prcs		*prcs_head;

	i = 0;
	while(i < vm->cycles_to_die)
	{
		prcs_head = vm->prcs;
		while (prcs_head)
		{
			if (prcs_head->waitcycle == 0)
				read_operation(vm->field, prcs_head);
			if (prcs_head->waitcycle > 0)
				(prcs_head->waitcycle)--;
			if (prcs_head->waitcycle == 0)
				exec_ops(prcs_head);
			prcs_head = prcs_head->next;
		}
		i++;
	}
	return (0);
}