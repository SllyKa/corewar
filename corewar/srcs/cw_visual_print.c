/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_visual_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 19:14:27 by bjesse            #+#    #+#             */
/*   Updated: 2019/12/24 02:08:53 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cw_vs_print_memory(unsigned char *arena, unsigned char *arena_info)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	while (i < MEM_SIZE)
	{
		y = i / 64 + 1;
		x = 2 * i % 128;
		x += x / 2;
		mvwaddch(get_window(), y, x + 1,
		ft_itoa_char(arena[i] / 16) | COLOR_PAIR(arena_info[i]));
		mvwaddch(get_window(), y, x + 2,
		ft_itoa_char(arena[i] % 16) | COLOR_PAIR(arena_info[i]));
		i++;
	}
}

void	cw_vs_print_players(t_vm *vm)
{
	t_plr_ardata	*now_player;
	int				y;

	now_player = vm->plrdata;
	y = 15;
	while (now_player)
	{
		wmove(get_window(), y++, MEM_WIDTH + 4);
		wprintw(get_window(), "player %s", now_player->name);
		wmove(get_window(), y++, MEM_WIDTH + 8);
		wprintw(get_window(), "live : %d", now_player->liven);
		now_player = now_player->next;
		y++;
	}
}

double	g_delay;

void	cw_vs_print_info(t_vm *vm)
{
	wmove(get_window(), 1, MEM_WIDTH);
	wvline(get_window(), '*' | A_STANDOUT, MEM_HEIGHT);
	wmove(get_window(), 3, MEM_WIDTH + 4);
	wprintw(get_window(), "Delay : %d", (int)(g_delay));
	wmove(get_window(), 5, MEM_WIDTH + 4);
	wprintw(get_window(), "Cycle : %d", vm->cyclen);
	wmove(get_window(), 7, MEM_WIDTH + 4);
	wprintw(get_window(), "CYCLE_TO_DIE : %d", vm->cycles_to_die);
	wmove(get_window(), 9, MEM_WIDTH + 4);
	wprintw(get_window(), "LIVEN : %d", vm->liven);
	wmove(get_window(), 11, MEM_WIDTH + 4);
	wprintw(get_window(), "PROCESS : %d", get_process_quan(vm));
	wmove(get_window(), 13, MEM_WIDTH + 4);
	wprintw(get_window(), "IS_DEBUG : %d", g_is_debug);
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
		x += x / 2;
		to_print = arena[i];
		mvwaddch(get_window(), y + 1, x + 1,
		ft_itoa_char(to_print % 16) | A_STANDOUT | COLOR_PAIR(3));
		mvwaddch(get_window(), y + 1, x,
		ft_itoa_char(to_print / 16) | A_STANDOUT | COLOR_PAIR(3));
		prcs = prcs->next;
	}
}

void	cw_vs_print_frame(t_vm *vm)
{
	long int	input;

	cw_vs_clear_windows();
	box(get_window(), '*' | A_STANDOUT, '*' | A_STANDOUT);
	cw_vs_print_memory(vm->field, vm->vsfield);
	cw_vs_print_prcs(vm->prcs, vm->field);
	cw_vs_print_info(vm);
	cw_vs_refresh_windows();
	input = getch();
	if (input == ' ' || g_is_debug)
		pause_game();
	if (input == 27 || input == 'q')
		exit(0);
	if (input == 'd')
		g_is_debug = !g_is_debug;
	if (input == KEY_UP && g_delay > 3)
		g_delay /= 1.1;
	else if (input == KEY_DOWN && g_delay < 100000)
		g_delay *= 1.1;
	if (g_delay == 0)
		g_delay = 100000;
	usleep((int)(g_delay));
	wmove(get_window(), 20, MEM_WIDTH + 4);
}
