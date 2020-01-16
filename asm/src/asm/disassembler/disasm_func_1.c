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

void			write_name(int fd, t_plr_ardata *champ)
{
	write(fd, ".name\t\t\"", 8);
	write(fd, champ->name, ft_strlen(champ->name));
	write(fd, "\"\n", 2);
}

void			write_comment(int fd, t_plr_ardata *champ)
{
	write(fd, ".comment\t\"", 10);
	write(fd, champ->comment, ft_strlen(champ->comment));
	write(fd, "\"\n\n", 3);
}

static size_t	typebyte_to_byten(unsigned char arg, char command)
{
	size_t		passn;

	passn = 0;
	if (arg == 0)
		return (passn);
	if (arg == REG_CODE)
		passn += CODE_REG_SIZE;
	else if (arg == DIR_CODE)
	{
		if (g_op_tab[command - 1].isadress == 1)
			passn += IND_SIZE;
		else
			passn += DIR_SIZE;
	}
	else if (arg == IND_CODE)
		passn += IND_SIZE;
	return (passn);
}

size_t			pass_bytes(unsigned char typebyte, char command)
{
	size_t			passn;

	passn = 1;
	passn += typebyte_to_byten((typebyte >> 6) & 3, command);
	if (g_op_tab[command - 1].argnum < 2)
		return (passn);
	passn += typebyte_to_byten((typebyte >> 4) & 3, command);
	if (g_op_tab[command - 1].argnum < 3)
		return (passn);
	passn += typebyte_to_byten((typebyte >> 2) & 3, command);
	return (passn);
}

char			*arrgs_chse(int fd, char *code,
					unsigned char argtype, char command)
{
	if (command == 9 || command == 12 || command == 15)
		write(fd, "%", 1);
	if (argtype == T_REG)
	{
		write(fd, "r", 1);
		ft_putnbr_fd(ops_read_treg(code, 0), fd);
		return (code + CODE_REG_SIZE);
	}
	else if (argtype == T_DIR)
	{
		write(fd, "%", 1);
		ft_putnbr_fd(ops_read_tdir(code, 0,
				typebyte_to_byten(argtype, command)), fd);
		return (code + typebyte_to_byten(argtype, command));
	}
	ft_putnbr_fd(ops_read_tind(code, 0), fd);
	return (code + IND_SIZE);
}
