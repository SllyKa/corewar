

#include "corewar.h"


void cw_vs_print_memory(unsigned char *arena)
{
	int i;
	WINDOW	*win;
	int x;
	int y;

	i = 0;
	win = get_window();
	box(win, '*' | A_STANDOUT, '*' | A_STANDOUT);
	while (i < MEM_SIZE)
	{
		y = i / 64 + 1;
		x = 2*i % 128;
		mvwaddch(win, y, x + 1, '0' + arena[i] % 16); // | COLOR_PAIR(3)
		mvwaddch(win, y, x + 2, '0' + arena[i] / 16); // | COLOR_PAIR(3)
		i++;
	}
}



double g_delay;
void cw_vs_print_info(t_vm* vm)
{
	WINDOW	*win;

	win = get_window();
	wmove(win, 3, MEM_WIDTH + 4);
	wprintw(win, "Cycle : %d", vm->cyclen);
	wmove(win, 5, MEM_WIDTH + 4);
	wprintw(win, "CYCLE_TO_DIE : %d", vm->cycles_to_die);
	wmove(win, 7, MEM_WIDTH + 4);
	wprintw(win, "Delay : %d", (int)(g_delay));
}

void cw_vs_print_prcs(t_prcs *prcs, unsigned char *arena)
{
	int i;
	int x;
	int y;
	char to_print;

	while (prcs)
	{
		i = prcs->pc;
		y = i / 64;
		x = 2*i % 128 + 1;
		to_print = arena[i];
		mvwaddch(get_window(), y + 1, x + 1, '0' + to_print / 16 | A_STANDOUT); // | COLOR_PAIR(3)
		mvwaddch(get_window(), y + 1, x, '0' + to_print % 16 | A_STANDOUT); // | COLOR_PAIR(3)
		prcs = prcs->next;
	}
}


void cw_vs_print_frame(t_vm* vm, t_prcs *first_prcs)
{
	long int input;

	cw_vs_clear_windows();
	cw_vs_print_memory(vm->field);
	cw_vs_print_prcs(first_prcs, vm->field);
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
