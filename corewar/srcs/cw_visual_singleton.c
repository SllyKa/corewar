

#include "corewar.h"





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


WINDOW	*get_mem_window()
{
	return (*mem_window_singleton());
}

WINDOW	*get_info_window()
{
	return (*info_window_singleton());
}



