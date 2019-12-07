
#include "cw_structs.h"
#include <ncurses.h>

WINDOW	*get_mem_window();

WINDOW	*get_info_window();

WINDOW	**info_window_singleton(void);
WINDOW	**mem_window_singleton(void);


void init_visual();
void cw_vs_print_frame(t_vm* vm, t_prcs *first_prcs);

void cw_vs_clear_windows();
void cw_vs_refresh_windows();



void	init_info_window();
void	init_mem_window();
void	reinit_visual();


