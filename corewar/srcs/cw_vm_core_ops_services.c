/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_core_ops_services.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 14:59:40 by gbrandon          #+#    #+#             */
/*   Updated: 2019/12/04 15:21:19 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	plrs_lives_upd(t_plr_ardata *plrdata, int uid)
{
	t_plr_ardata	*pl;

	pl = plrdata;
	while (pl)
	{
		if (pl->uid == uid)
			(pl->liven)++;
		pl = pl->next;
	}
}

void		cw_vm_core_upd_live(t_vm *vm, int uid)
{
	vm->lastlive = vm->cyclen;
	(vm->liven)++;
	plrs_lives_upd(vm->plrdata, uid);
}