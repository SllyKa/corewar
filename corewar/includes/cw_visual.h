
#include "cw_structs.h"
#include <ncurses.h>
#include <unistd.h>

WINDOW	*get_window();

WINDOW	**window_singleton(void);


void init_visual();
void cw_vs_print_frame(t_vm* vm, t_prcs *first_prcs);

void cw_vs_clear_windows();
void cw_vs_refresh_windows();



void	init_window();
void	reinit_visual();


