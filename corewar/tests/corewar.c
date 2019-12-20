/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 12:23:20 by gbrandon          #+#    #+#             */
/*   Updated: 2019/12/20 06:10:09 by gbrandon         ###   ########.fr       */
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
	plrs = add_plrdata(plrs, 3, "\x02\xD0\xff\xff\x0B\x02\xD0\x00\x05\x0e\x00\x00\x00\xff\x0B\x58\x0B\x01\xff\xfezbsbdsbdsghdshwerpisdfkpew,sfa", 50);
	plrs = add_plrdata(plrs, 4, "\x02\x90\x00\x00\x00\x00\x0f\x09\x00\x03\x0F\xff\xf0wovmekwmvodsmvo;mdonvsdxc&*(", 42);
	plrs = add_plrdata(plrs, 5, "\x01\xff\xff\xff\xfb\x02\x90\x00\x00\x00\x00\x0f\x09\xff\xf4lllll", 21);
	//		--(and or xor)reg reg reg
	//plrs = add_plrdata(plrs, 6, "\x02\xD0\xff\xfe\x05\x02\x90\x00\x0f\x10\x11\x0A\x08\x54\x05\x0A\x0fzzzzz", 24);
	//		--(and or xor) ind dir reg
	plrs = add_plrdata(plrs, 6, "\x02\xD0\xff\xfe\x05\x02\x90\x00\x0f\x10\x11\x0A\x06\xE4\xff\xf9\x00\x07\x00\x01\x0fzzzzz", 28);
	//		--(lld)
	//plrs = add_plrdata(plrs, 6, "\x0D\xD0\xfd\xb5\x0dlllll", 13);
	// 		--(ldi)
	//plrs = add_plrdata(plrs, 7, "\x02\xD0\xff\xfe\x05\x02\x90\x00\x00\x01\x34\x0A\x0A\x94\xfe\xca\x0A\x0fzzzzz", 26);
	//		--(lldi)
	plrs = add_plrdata(plrs, 7, "\x02\xD0\xff\xfe\x05\x02\x90\x00\x00\x01\x34\x0A\x0E\x94\x80\x01\x0A\x0fzzzzz", 26);
	//		--(aff)
	plrs = add_plrdata(plrs, 8, "\x02\x90\x7f\xff\xff\x5a\x02\x10\x40\x02!@#$sdgfg^&*", 26);
	arena = cw_arena_init(plrs);
	cw_vm_memdump(arena);
	arena->prcs = cw_prcs_init(arena);
	cw_fight(arena);

	return (0);
}