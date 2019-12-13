
#include "corewar.h"


void cw_vs_clear_windows()
{
	werase(get_window());
}

void cw_vs_refresh_windows()
{
	wrefresh(get_window());
}


void	init_window()
{
	*window_singleton() = newwin(MEM_HEIGHT + 2, MEM_WIDTH + 42, 0, 0);
}


void	reinit_visual()
{
	delwin(get_window());
    endwin();
}