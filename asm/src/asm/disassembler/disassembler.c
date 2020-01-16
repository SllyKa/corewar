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

void			write_arg(int fd, char *code)
{
	int		i;
	char	command;
	char	typebyte;

	i = 0;
	command = code[0] - 1;
	typebyte = code[1];
	code += 2;
	while (i < g_op_tab[(unsigned char)command].argnum)
	{
		if (i > 0)
			write(fd, ",", 1);
		if (command + 1 == 1)
			code = arrgs_chse(fd, code - 1, T_DIR, command + 1);
		else if (command + 1 == 9)
			code = arrgs_chse(fd, code - 1, T_IND, command + 1);
		else if ((command + 1 == 12) || (command + 1 == 15))
			code = arrgs_chse(fd, code - 1, T_IND, command + 1);
		else
			code = arrgs_chse(fd, code,
	vm_core_ops_argn_type((unsigned char)typebyte, i + 1), command + 1);
		i++;
	}
}

unsigned char	typebyte_to_arg_type(unsigned char arg)
{
	if (arg == 0)
		return (arg);
	if (arg == REG_CODE)
		arg = T_REG;
	else if (arg == DIR_CODE)
		arg = T_DIR;
	else if (arg == IND_CODE)
		arg = T_IND;
	return (arg);
}

static char		*exec_ops(int fd, char *code)
{
	unsigned char		typebyte;
	char				*name;

	typebyte = code[1];
	name = g_op_tab[code[0] - 1].name;
	write(fd, "\t", 1);
	write(fd, name, ft_strlen(name));
	write(fd, "       ", 6 - ft_strlen(name));
	write_arg(fd, code);
	write(fd, "\n", 1);
	if (code[0] == 1)
		code += 1 + DIR_SIZE;
	else if (code[0] == 9)
		code += 1 + IND_SIZE;
	else if ((code[0] == 12) || (code[0] == 15))
		code += 1 + IND_SIZE;
	else
		code += 1 + pass_bytes(typebyte, code[0]);
	return (code);
}

void			write_code(int fd, char *code)
{
	while (*code)
	{
		if (check_opsign(code) > 0)
			code = exec_ops(fd, code);
		else
			read_error("Error in code");
	}
}

void			disassembler(char *filename)
{
	int				fd;
	t_plr_ardata	*champ;

	if ((fd = open(filename, O_RDONLY)) < 0)
		read_error("There's no file");
	champ = 0;
	parse_champ(&champ, 0, fd);
	close(fd);
	filename[ft_strlen(filename) - 3] = 's';
	filename[ft_strlen(filename) - 2] = '\0';
	if ((fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0644)) < 0)
		read_error("Can't create file");
	write_name(fd, champ);
	write_comment(fd, champ);
	write_code(fd, champ->data);
	free_champ(champ);
	close(fd);
}
