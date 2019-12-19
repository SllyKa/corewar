/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_core_check_ops_services.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 12:37:23 by gbrandon          #+#    #+#             */
/*   Updated: 2019/12/20 01:31:46 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern t_op g_op_tab[17];

static size_t	arg_type_to_size(unsigned char opcode, t_arg_type val)
{
	if (val == 0)
		return (val);
	else if ((T_REG & val) == T_REG)
		return (CODE_REG_SIZE);
	else if ((T_DIR & val) == T_DIR)
	{
		if (g_op_tab[opcode - 1].isadress)
			return(IND_SIZE);
		else
			return (DIR_SIZE);
	}
	else if ((T_IND & val) == T_IND)
		return (IND_SIZE);
	return (val);
}

int				chk_reg_valid(t_vm *vm, t_prcs *prc, unsigned char opcode,
		unsigned char typebyte)
{
	int				i;
	int				tonext;
	int				reg_val;

	i = 0;
	tonext = ((g_op_tab[opcode - 1].istypeb == 0) ? 1 : 2);
	while (i < 3)
	{
		if ((T_REG & vm_core_ops_argn_type(typebyte, i + 1)) == T_REG)
		{
			reg_val = ops_read_treg(vm->field, vm_add_address(prc->pc, tonext));
			if ((reg_val >= REG_NUMBER) || (reg_val <= 0))
				return (-1);
			tonext += CODE_REG_SIZE;
		}
		else
			tonext += arg_type_to_size(opcode, vm_core_ops_argn_type(typebyte, i + 1));
		i++;
	}
	return (0);
}

unsigned char	typebyte_to_arg_type(unsigned char arg)
{
	if (arg == 0)
		return arg;
	if (arg == REG_CODE)
		arg = T_REG;
	else if (arg == DIR_CODE)
		arg = T_DIR;
	else if (arg == IND_CODE)
		arg = T_IND;
	return (arg);
}
