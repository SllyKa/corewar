

#include "corewar.h"


WINDOW	**window_singleton(void)
{
	static WINDOW *win;

	return (&win);
}



WINDOW	*get_window()
{
	return (*window_singleton());
}
