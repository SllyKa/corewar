/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 12:23:20 by gbrandon          #+#    #+#             */
/*   Updated: 2019/12/04 16:09:55 by gbrandon         ###   ########.fr       */
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
	plrs = add_plrdata(plrs, 5, "\x01\x0\x80\x80\x80llll", 9);
	arena = cw_arena_init(plrs);
	cw_vm_memdump(arena);
	arena->prcs = cw_prcs_init(arena, plrs);
	cw_fight(arena);

	return (0);
}