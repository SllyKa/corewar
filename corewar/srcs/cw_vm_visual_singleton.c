

#include "corewar.h"
#include <ncurses.h>




WINDOW	**mem_window_singleton(void)
{
	static WINDOW *win;

	return (&win);
}

WINDOW	**info_window_singleton(void)
{
	static WINDOW *win;

	return (&win);
}

void	init_mem_window()
{
	printf("init\n");
	*mem_window_singleton() = newwin(MEM_HEIGHT + 2, MEM_WIDTH + 2, 0, 0);
}

void	init_info_window()
{
	*info_window_singleton() = newwin(INFO_HEIGHT, INFO_WIDTH, 0, MEM_WIDTH + 2);
}

WINDOW	*get_mem_window()
{
	return (*mem_window_singleton());
}

WINDOW	*get_info_window()
{
	return (*info_window_singleton());
}


void cw_vs_print_memory(unsigned char *arena)
{
	int i;
	WINDOW	*win;
	int x;
	int y;

	i = 0;
	win = get_mem_window();
	box(win, 0, 0);
	while (i < MEM_SIZE)
	{
		y = i / 64 + 1;
		x = 2*i % 128;
		mvwaddch(win, y, x + 1, '0' + arena[i] % 16); // | COLOR_PAIR(3)
		mvwaddch(win, y, x + 2, '0' + arena[i] / 16); // | COLOR_PAIR(3)
		i++;
	}
}


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


void cw_vs_print_info(t_vm* vm)
{
	WINDOW	*win;

	win = get_info_window();
	// printf("%p\n", win);
	// wclear(win);
	// werase(win);
	box(win, 0, 0);
}

void cw_vs_print_prcs(t_prcs *prcs, unsigned char *arena)
{
	int i;
	int x;
	int y;
	char to_print;

	while (prcs)
	{
		i = prcs->pc / 2;
		y = i / 64 + 1;
		x = 2*i % 128;
		to_print = arena[i];
		if (prcs->pc % 2)
			to_print = '0' + to_print % 16;
		else
			to_print = '0' + to_print / 16;
		mvwaddch(get_mem_window(), y, x + prcs->pc % 2, to_print | A_STANDOUT); // | COLOR_PAIR(3)
		prcs = prcs->next;
	}
}

void cw_vs_print_frame(t_vm* vm, t_prcs *first_prcs)
{
	cw_vs_clear_windows();
	cw_vs_print_memory(vm->field);
	// cw_vs_print_prcs(first_prcs, vm->field);
	cw_vs_print_info(vm);

	cw_vs_refresh_windows();
}


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
	timeout(10000);
	use_default_colors();
	start_color();
	printf("colors: %d\n", COLORS);
	init_mem_window();
	init_info_window();
	make_colors();
	wattron(get_mem_window(), COLOR_PAIR(0) );
}


void	reinit_visual()
{
	delwin(get_mem_window());
	delwin(get_info_window());
    endwin();
}