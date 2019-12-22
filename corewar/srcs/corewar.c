/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 06:10:41 by gbrandon          #+#    #+#             */
/*   Updated: 2019/12/22 04:15:01 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	g_flags = 0;
int		g_verbf = 0;
int		g_memdmp = 0;

#include "corewar.h"
#include "corewar_start.h"

int		main(int argc, char **argv)
{
	t_vm				*vm;
	t_plr_ardata		*plrardata;
	
	if (!(plrardata = cw_vm_start(argc, argv)))
		return (0);
	vm = cw_arena_init(plrardata);
	cw_vm_memdump(vm);
	vm->prcs = cw_prcs_init(vm);
	cw_fight(vm);
	cw_free_vm(vm);
	return (0);
}