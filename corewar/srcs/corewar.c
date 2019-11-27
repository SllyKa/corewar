/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 12:23:20 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/27 19:24:23 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		main(int argc, char **argv)
{
	t_plr_ardata	*plrs;
	t_vm			*arena;

	(void)argc;
	(void)argv;

	plrs = NULL;
	plrs = add_plrdata(plrs, 1, "12345aghnbtuyop\0qwe\xff", 20);
	plrs = add_plrdata(plrs, 2, "!@#$sdgfg^&*", 12);
	plrs = add_plrdata(plrs, 3, "dsgdsgbdsbdsbdsbdsghdshwerpisdfkpew,sf", 38);
	plrs = add_plrdata(plrs, 4, "dskogmnwovmekwmvodsmvo;mdonvsdxc&*(", 35);
	plrs = add_plrdata(plrs, 5, "llll", 4);
	arena = cw_arena_init(plrs);
	cw_vm_memdump(arena);
	arena->prcs = cw_prcs_init(plrs);
	

	return (0);
}