





#include "corewar.h"


void error_exit(char *str)
{
	ft_printf("%s", str);
	exit();
}

int check_magick_number(int fd)
{
	char buff[5];
	if (read(fd, buff, 4) != 4)
		error_exit("bad magic num!\n");
	buff[4] = 0;
	printf("%d")
}



int parse_champ(t_plr_ardata **plr, int champ_num, int fd)
{
	char *name;
	char *comment;
	char *code;
	int code_size;
	check_magick_number(fd);
	read_champ_name(&name, fd);
	read_zero_bytes(fd, 4);
	code_size = read_code_size(fd);
	comment = read_code_comment(fd);
	read_zero_bytes(fd, 4);
	code = read_champ_code(fd, code_size);
}