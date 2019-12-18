/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_core_ops_services.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 14:59:40 by gbrandon          #+#    #+#             */
/*   Updated: 2019/12/18 19:53:58 by gbrandon         ###   ########.fr       */
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
			(pl->liven)++;
		pl = pl->next;
	}
}

void			cw_vm_core_upd_live(t_vm *vm, int uid)
{
	vm->lastlive = vm->cyclen;
	(vm->liven)++;
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
