


#include "disasm.h"
extern t_op g_op_tab[17];
void write_name(int fd, t_plr_ardata *champ)
{
	write(fd, ".name\t\t\"", 8);
	printf("%s\n", champ->name);

	write(fd, champ->name, ft_strlen(champ->name));
	write(fd, "\"\n", 2);
}

void write_comment(int fd, t_plr_ardata *champ)
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



char				*arrgs_chse(int fd, char *code, unsigned char argtype, char command)
{
	int				reg;
	int				val;

	val = 0;
	if (command == 9 || command == 12 || command == 15)
			write(fd, "%", 1);
	if (argtype == T_REG)
	{
		reg = ops_read_treg(code, 0);
		write(fd, "r", 1);
		ft_putnbr_fd(reg, fd);
		return (code + CODE_REG_SIZE);
	}
	else if (argtype == T_DIR)
	{
		val = ops_read_tdir(code, 0, typebyte_to_byten(argtype, command));
		write(fd, "%", 1);
		ft_putnbr_fd(val, fd);
		return (code + typebyte_to_byten(argtype, command));
	}
	else if (argtype == T_IND)
	{
		val = ops_read_tind(code, 0);
		ft_putnbr_fd(val, fd);
		return (code + IND_SIZE);
	}
	return (code);
}

void write_arg(int fd, char *code)
{
	int i;
	char command;
	char typebyte;

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
			code = arrgs_chse(fd, code, vm_core_ops_argn_type((unsigned char)typebyte, i + 1), command + 1);
		i++;
	}
}


static char	*exec_ops(int fd, char *code)
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

void write_code(int fd, char *code)
{
	while (*code)
	{
		if (check_opsign(code) > 0)
			code = exec_ops(fd, code);
		else
			read_error("Error in code");
	}
}


void disassembler(char *filename)
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
	printf("%s\n", filename);
	if ((fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0644)) < 0)
		read_error("Can't create file");
	write_name(fd, champ);
	write_comment(fd, champ);
	write_code(fd, champ->data);
	free_champ(champ);
	close(fd);
}