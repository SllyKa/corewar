/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_flags_verb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 05:03:23 by gbrandon          #+#    #+#             */
/*   Updated: 2019/12/22 07:25:13 by gbrandon         ###   ########.fr       */
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

void	cw_vm_flags_verb_cycle(t_vm *vm)
{
	if ((2 & g_flags) == 2)
		return ;
	if ((2 & g_verbf) == 2)
		ft_printf("cyclen: %d\n", vm->cyclen);
	if ((4 & g_verbf) == 4)
	{
		ft_printf("cycles_to_die: %d\n", vm->cycles_to_die);
		ft_printf("checkN: %d\n", vm->checkn);
		ft_printf("liven: %d\n", vm->liven);
		ft_printf("LAST_LIIIIIVE: %d\n", vm->lastlive);
	}
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
r_geti(prc->regs[0]), vm->cycles_to_die - prc->livecycle, vm->cycles_to_die);
}