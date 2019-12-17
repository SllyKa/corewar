/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_core_services.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:32:41 by gbrandon          #+#    #+#             */
/*   Updated: 2019/12/06 17:56:18 by gbrandon         ###   ########.fr       */
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

int				vm_btoi(unsigned char *bytes, size_t size)
{
	char			in[4];
	size_t			up;
	size_t			i;

	i = 0;
	while (i < 4)
	{
		in[i] = 0;
		i++;
	}
	i = 0;
	up = 4;
	if (size < 4)
		up = size;
	while (i < up)
	{
		in[i] =  bytes[size - 1 - i];
		i++;
	}
	return (*((int*)in));
}

int				chk_opcode(unsigned char opcode)
{
	if (opcode < 1 || opcode > 16)
		return (-1);
	return (1);
}
