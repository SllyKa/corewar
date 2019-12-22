/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 06:10:41 by gbrandon          #+#    #+#             */
/*   Updated: 2019/12/22 07:05:06 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_start.h"

char	g_flags = 0;
int		g_verbf = 0;
int		g_memdmp = 0;

int		main(int argc, char **argv)
{
	t_vm				*vm;
	t_plr_ardata		*plrardata;

	if (!(plrardata = cw_vm_start(argc, argv)))
		return (0);
	cw_vm_introduce_players(plrardata);
	vm = cw_arena_init(plrardata);
	cw_vm_memdump(vm);
	vm->prcs = cw_prcs_init(vm);
	cw_fight(vm);
	cw_vm_won_player(vm);
	cw_free_vm(vm);
	return (0);
}
