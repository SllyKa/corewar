/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_visual_work.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 19:14:33 by bjesse            #+#    #+#             */
/*   Updated: 2019/12/24 02:04:17 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cw_vs_clear_windows(void)
{
	werase(get_window());
}

void	cw_vs_refresh_windows(void)
{
	wrefresh(get_window());
}

void	init_window(void)
{
	*window_singleton() = newwin(MEM_HEIGHT + 2,
	MEM_WIDTH + INFO_WIDTH + 2, 0, 0);
}

void	reinit_visual(void)
{
	delwin(get_window());
	endwin();
}

void	pause_game(void)
{
	char	input;

	wmove(get_window(), 1, MEM_WIDTH + 4);
	wprintw(get_window(), "PAUSE");
	cw_vs_refresh_windows();
	while ((input = getch()) == ERR)
		;
	if (input == 27 || input == 'q')
	{
		exit(0);
		destroy_visual();
	}
	if (input == 'd')
		g_is_debug = !g_is_debug;
}
