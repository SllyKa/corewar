/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_flags_verb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 05:03:23 by gbrandon          #+#    #+#             */
/*   Updated: 2020/01/09 19:01:26 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern int	g_flags;
extern int	g_verbf;

void	cw_vm_flags_verb_live(t_plr_ardata *plrdata)
{
	if ((2 & g_flags) == 2)
		return ;
	if ((1 & g_verbf) != 1)
		ft_printf("A process shows that player %d (%s) is alive.\n",
		plrdata->uid, plrdata->name);
}

void	cw_vm_flags_verb_detcycle(t_vm *vm)
{
	if ((2 & g_flags) == 2)
		return ;
	if ((4 & g_verbf) == 4)
	{
		ft_printf("cyclen:\t%d\n", vm->cyclen);
		ft_printf("cycles_to_die:\t%d\n", vm->cycles_to_die);
		ft_printf("checkN:\t%d\n", vm->checkn);
		ft_printf("liven:\t%d\n", vm->liven);
		ft_printf("LAST_LIIIIIVE:\t%d\n", vm->lastlive);
		ft_printf("\n");
	}
}

void	cw_vm_flags_verb_cycle(t_vm *vm)
{
	if ((2 & g_flags) == 2)
		return ;
	if ((2 & g_verbf) == 2)
		ft_printf("cyclen: %d\n", vm->cyclen);
}

void	cw_vm_flags_verb_unitpos(t_prcs *prc)
{
	if ((2 & g_flags) == 2)
		return ;
	if ((8 & g_verbf) == 8)
		ft_printf("uid: %d | cur_pos: %d | oper_code: %.2x\n",
		r_geti(prc->regs[0]), prc->pc, prc->curop);
}

void	cw_vm_flags_verb_deaths(t_prcs *prc, t_vm *vm)
{
	if ((2 & g_flags) == 2)
		return ;
	if ((16 & g_verbf) == 16)
		ft_printf("Process %d is dead for %d cycles (CTD: %d)\n",
	prc->uid, vm->cyclen - 1 - prc->livecycle, vm->cycles_to_die);
}
