/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_visual_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 19:14:27 by bjesse            #+#    #+#             */
/*   Updated: 2019/12/21 19:14:39 by bjesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cw_vs_print_memory(unsigned char *arena)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	box(get_window(), '*' | A_STANDOUT, '*' | A_STANDOUT);
	while (i < MEM_SIZE)
	{
		y = i / 64 + 1;
		x = 2 * i % 128;
		mvwaddch(get_window(), y, x + 1, '0' + arena[i] % 16); // | COLOR_PAIR(3)
		mvwaddch(get_window(), y, x + 2, '0' + arena[i] / 16); // | COLOR_PAIR(3)
		i++;
	}
}

void	cw_vs_print_players(t_vm *vm)
{
	t_plr_ardata	*now_player;
	int				y;

	now_player = vm->plrdata;
	y = 11;
	while (now_player)
	{
		wmove(get_window(), y++, MEM_WIDTH + 4);
		wprintw(get_window(), "player %s", now_player->name);
		wmove(get_window(), y++, MEM_WIDTH + 8);
		wprintw(get_window(), "live : %d", now_player->liven);
		y++;
	}
}

double	g_delay;

void	cw_vs_print_info(t_vm *vm)
{
	wmove(get_window(), 3, MEM_WIDTH + 4);
	wprintw(get_window(), "Delay : %d", (int)(g_delay));
	wmove(get_window(), 5, MEM_WIDTH + 4);
	wprintw(get_window(), "Cycle : %d", vm->cyclen);
	wmove(get_window(), 7, MEM_WIDTH + 4);
	wprintw(get_window(), "CYCLE_TO_DIE : %d", vm->cycles_to_die);
	wmove(get_window(), 9, MEM_WIDTH + 4);
	wprintw(get_window(), "LIVEN : %d", vm->liven);
	cw_vs_print_players(vm);
}

void	cw_vs_print_prcs(t_prcs *prcs, unsigned char *arena)
{
	int		i;
	int		x;
	int		y;
	char	to_print;

	while (prcs)
	{
		i = prcs->pc;
		y = i / 64;
		x = 2 * i % 128 + 1;
		to_print = arena[i];
		mvwaddch(get_window(), y + 1, x + 1, '0' + to_print / 16 | A_STANDOUT); // | COLOR_PAIR(3)
		mvwaddch(get_window(), y + 1, x, '0' + to_print % 16 | A_STANDOUT); // | COLOR_PAIR(3)
		prcs = prcs->next;
	}
}

void	cw_vs_print_frame(t_vm *vm)
{
	long int	input;

	cw_vs_clear_windows();
	cw_vs_print_memory(vm->field);
	cw_vs_print_prcs(vm->prcs, vm->field);
	cw_vs_print_info(vm);
	cw_vs_refresh_windows();
	input = getch();
	if (input == KEY_UP && g_delay > 3)
		g_delay /= 1.1;
	else if (input == KEY_DOWN && g_delay < 100000)
		g_delay *= 1.1;
	if (g_delay == 0)
		g_delay = 100000;
	usleep((int)(g_delay));
}
