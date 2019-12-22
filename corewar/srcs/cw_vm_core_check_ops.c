/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_core_check_ops.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 21:09:31 by gbrandon          #+#    #+#             */
/*   Updated: 2019/12/22 07:10:40 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern t_op g_op_tab[17];

static int		chk_types_byte(unsigned char opcode, unsigned char typebyte)
{
	unsigned char	arg;

	if (!(arg = typebyte_to_arg_type((typebyte >> 6) & 3))
	&& (g_op_tab[opcode - 1].argtype[0]))
		return (-1);
	if ((arg & g_op_tab[opcode - 1].argtype[0]) != arg)
		return (-1);
	if (!(arg = typebyte_to_arg_type((typebyte >> 4) & 3))
	&& (g_op_tab[opcode - 1].argtype[1]))
		return (-1);
	if ((arg & g_op_tab[opcode - 1].argtype[1]) != arg)
		return (-1);
	if (!(arg = typebyte_to_arg_type((typebyte >> 2) & 3))
	&& (g_op_tab[opcode - 1].argtype[2]))
		return (-1);
	if ((arg & g_op_tab[opcode - 1].argtype[2]) != arg)
		return (-1);
	return (1);
}

static size_t	typebyte_to_byten(unsigned char arg)
{
	size_t		passn;

	passn = 0;
	if (arg == 0)
		return (passn);
	if (arg == REG_CODE)
		passn += CODE_REG_SIZE;
	// have to add 2 or 4 choose further
	else if (arg == DIR_CODE)
		passn += DIR_SIZE;
	else if (arg == IND_CODE)
		passn += IND_SIZE;
	return (passn);
}

size_t			pass_bytes(unsigned char typebyte)
{
	size_t			passn;
	size_t			res;

	passn = 1;
	if (!(res = typebyte_to_byten((typebyte >> 6) & 3)))
		return (passn + res);
	passn += res;
	if (!(res = typebyte_to_byten((typebyte >> 4) & 3)))
		return (passn + res);
	passn += res;
	if (!(res = typebyte_to_byten((typebyte >> 2) & 3)))
		return (passn + res);
	passn += res;
	return (passn);
}

int				check_opsign(t_vm *vm, t_prcs *prc)
{
	unsigned char		typebyte;

	typebyte = deref_pntr(vm->field, vm_add_address(prc->pc, 1));
	if (chk_opcode(prc->curop) < 0)
		prc->pc = vm_add_address(prc->pc, 1);
	else
	{
		if (g_op_tab[prc->curop - 1].istypeb == 1 &&
		chk_types_byte(prc->curop, typebyte) < 0)
			prc->pc = vm_add_address(prc->pc, 1 + pass_bytes(typebyte));
		else
		{
			if (g_op_tab[prc->curop - 1].istypeb == 1 &&
			chk_reg_valid(vm, prc, prc->curop, typebyte) < 0)
				prc->pc = vm_add_address(prc->pc, 1 + pass_bytes(typebyte));
			else
				return (1);
		}
	}
	return (-1);
}
