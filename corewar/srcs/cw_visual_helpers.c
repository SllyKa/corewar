/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_visual_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 19:14:21 by bjesse            #+#    #+#             */
/*   Updated: 2019/12/21 19:14:23 by bjesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		get_process_quan(t_vm *vm)
{
	t_prcs			*prcs;
	int				y;

	prcs = vm->prcs;
	y = 0;
	while (prcs)
	{
		prcs = prcs->next;
		y++;
	}
	return (y);
}