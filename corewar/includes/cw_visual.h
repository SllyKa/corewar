
#include "cw_structs.h"
#include <ncurses.h>
#include <unistd.h>

WINDOW	*get_window();

WINDOW	**window_singleton(void);

#define MEM_HEIGHT 64
# define MEM_WIDTH  192
# define INFO_HEIGHT 40
# define INFO_WIDTH 60

void init_visual();
void cw_vs_print_frame(t_vm* vm);

void cw_vs_clear_windows();
void cw_vs_refresh_windows();

void	pause_game(void);
void destroy_visual();

int		get_process_quan(t_vm *vm);


void	init_window();
void	reinit_visual();


