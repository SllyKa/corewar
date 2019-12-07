


#include "corewar.h"


void cw_vs_clear_windows()
{
	werase(get_mem_window());
	werase(get_info_window());
}

void cw_vs_refresh_windows()
{
	wrefresh(get_mem_window());
	wrefresh(get_info_window());
}


void	init_mem_window()
{
	*mem_window_singleton() = newwin(MEM_HEIGHT + 2, MEM_WIDTH + 2, 0, 0);
}

void	init_info_window()
{
	*info_window_singleton() = newwin(INFO_HEIGHT, INFO_WIDTH, 0, MEM_WIDTH + 2);
}

void	reinit_visual()
{
	delwin(get_mem_window());
	delwin(get_info_window());
    endwin();
}