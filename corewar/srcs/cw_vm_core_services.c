/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_core_services.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:32:41 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/30 18:36:10 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned char 	deref_pntr(unsigned char *field, size_t pntr)
{
	return (field[pntr]);
}

size_t			vm_add_address(size_t pc, int offset)
{
	pc = (pc + offset) % MEM_SIZE;
	return (pc);
}

int				chk_opcode(unsigned char opcode)
{
	if (opcode < 1 || opcode > 16)
		return (-1);
	return (1);
}
