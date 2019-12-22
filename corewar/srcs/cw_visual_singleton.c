/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_visual_singleton.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 19:14:30 by bjesse            #+#    #+#             */
/*   Updated: 2019/12/21 19:14:50 by bjesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

WINDOW	**window_singleton(void)
{
	static WINDOW *win;

	return (&win);
}

WINDOW	*get_window(void)
{
	return (*window_singleton());
}
