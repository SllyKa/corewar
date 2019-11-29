/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_core_exec_ops.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 21:09:31 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/29 21:25:25 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	exec_ops(t_prcs *prc)
{
	if (prc->curop < 1 || prc->curop > 16)
	{
		prc->pc = vm_add_address(prc->pc, 1);
	}
}