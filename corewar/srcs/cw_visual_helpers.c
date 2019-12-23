/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_visual_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 19:14:21 by bjesse            #+#    #+#             */
/*   Updated: 2019/12/24 02:02:56 by gbrandon         ###   ########.fr       */
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
