/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 12:23:20 by gbrandon          #+#    #+#             */
/*   Updated: 2019/12/18 20:59:35 by gbrandon         ###   ########.fr       */
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
	plrs = add_plrdata(plrs, 1, "\x02\x90\x7f\xff\xff\xff\x04\x02\x90\xff\xff\xff\xfe\x05\x05\x54\x04\x05\x02i45aghnbtuyop\0qwe\xff", 39);
	plrs = add_plrdata(plrs, 2, "\x02\x90\x00\x00\x00\x00\x02\x03\x70\x02\x00\x00!@#$sdgfg^&*", 26);
	plrs = add_plrdata(plrs, 3, "\x02\xD0\xff\xfe\x0e\x00\x00\x00\x01zbsbdsbdsghdshwerpisdfkpew,sfa", 41);
	plrs = add_plrdata(plrs, 4, "\x02\x90\x00\x00\x00\xff\x0fwovmekwmvodsmvo;mdonvsdxc&*(", 35);
	plrs = add_plrdata(plrs, 5, "\x01\xff\xff\xff\xfblllll", 10);
	arena = cw_arena_init(plrs);
	cw_vm_memdump(arena);
	arena->prcs = cw_prcs_init(arena);
	cw_fight(arena);

	return (0);
}