

#include "corewar.h"



void make_colors()
{
	init_pair(1,2,0);
	init_pair(2,1,0);
	init_pair(3,3,0);
	init_pair(4,4,0);
}

void init_visual()
{
	printf("init_visual\n");
	initscr();
	keypad(stdscr, true);
	nodelay(stdscr, true);
	curs_set(false);
	cbreak();
	noecho();
	timeout(5);
	use_default_colors();
	start_color();
	printf("colors: %d\n", COLORS);
	init_window();
	make_colors();
	// wattron(get_window(), COLOR_PAIR(1) );
}


