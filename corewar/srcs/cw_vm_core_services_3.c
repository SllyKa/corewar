/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_core_services_3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 02:17:24 by gbrandon          #+#    #+#             */
/*   Updated: 2019/12/24 02:36:04 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern int	g_memdmp;
extern char	g_flags;

int		cw_vm_chk_memdump(t_vm *vm)
{
	if ((g_memdmp > 0) && (g_memdmp == (int)(vm->cyclen - 1)))
	{
		if ((2 & g_flags) == 2)
			pause_game();
		else
		{
			cw_vm_memdump(vm);
			return (0);
		}
	}
}
