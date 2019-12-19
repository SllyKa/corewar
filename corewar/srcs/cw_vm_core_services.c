/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_core_services.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:32:41 by gbrandon          #+#    #+#             */
/*   Updated: 2019/12/19 22:30:04 by gbrandon         ###   ########.fr       */
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
	unsigned char	in[4];
	size_t			up;
	size_t			i;
	unsigned char	sign;

	i = 0;
	sign = (((bytes[0] >> 7 & 1) == 1) ? '\xff' : 0);
	while (i < 4)
	{
		in[i] = sign;
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

t_prcs			*add_prc(t_prcs *head, t_prcs *new)
{
	if (!new)
		return (NULL);
	new->next = head;
	head = new;
	return (head);
}