/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_visual_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 19:14:21 by bjesse            #+#    #+#             */
/*   Updated: 2019/12/21 19:14:23 by bjesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	make_colors(void)
{
	init_pair(1, 2, 0);
	init_pair(2, 1, 0);
	init_pair(3, 3, 0);
	init_pair(4, 4, 0);
	init_pair(5, 5, 0);
	init_pair(6, 6, 0);
}

void	init_visual(void)
{
	initscr();
	keypad(stdscr, true);
	nodelay(stdscr, true);
	curs_set(false);
	cbreak();
	noecho();
	timeout(5);
	use_default_colors();
	start_color();
	init_window();
	make_colors();
	wrefresh(stdscr);
}

void	destroy_visual(void)
{
	delwin(get_window());
	endwin();
}
