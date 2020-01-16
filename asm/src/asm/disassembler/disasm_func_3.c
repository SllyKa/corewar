/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disassembler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 20:01:37 by bjesse            #+#    #+#             */
/*   Updated: 2020/01/16 20:01:39 by bjesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

extern t_op g_op_tab[17];

int				chk_opcode(unsigned char opcode)
{
	if (opcode < 1 || opcode > 16)
		return (-1);
	return (1);
}

int				check_opsign(char *code)
{
	unsigned char		typebyte;

	typebyte = code[1];
	if (chk_opcode(code[0]) < 0)
		return (-1);
	else
	{
		if (g_op_tab[code[0] - 1].istypeb == 1 &&
		chk_types_byte(code[0], typebyte) < 0)
			return (-1);
		else
		{
			if (g_op_tab[code[0] - 1].istypeb == 1 &&
			chk_reg_valid(code, code[0], typebyte) < 0)
				return (-1);
			else
				return (1);
		}
	}
	return (-1);
}

void			free_champ(t_plr_ardata *plr)
{
	free(plr->name);
	free(plr->comment);
	free(plr->data);
	free(plr);
}
