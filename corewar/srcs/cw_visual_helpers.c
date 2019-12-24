/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_visual_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 19:14:21 by bjesse            #+#    #+#             */
/*   Updated: 2019/12/24 02:02:56 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		get_process_quan(t_vm *vm)
{
	t_prcs			*prcs;
	int				y;

	prcs = vm->prcs;
	y = 0;
	while (prcs)
	{
		prcs = prcs->next;
		y++;
	}
	return (y);
}

void	cw_vs_print_win(t_vm *vm, char *name)
{
	cw_vs_clear_windows();
	box(get_window(), '*' | A_STANDOUT, '*' | A_STANDOUT);
	cw_vs_print_memory(vm->field, vm->vsfield);
	cw_vs_print_prcs(vm->prcs, vm->field);
	cw_vs_print_info(vm);
	cw_vs_refresh_windows();
	wmove(get_window(), 1, MEM_WIDTH + 4);
	wprintw(get_window(), "Champinion %s win!", name);
	getch();
}