/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_visual_work.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 19:14:33 by bjesse            #+#    #+#             */
/*   Updated: 2019/12/21 19:14:36 by bjesse           ###   ########.fr       */
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
	*window_singleton() = newwin(MEM_HEIGHT + 2, MEM_WIDTH + 42, 0, 0);
}

void	reinit_visual(void)
{
	delwin(get_window());
	endwin();
}
