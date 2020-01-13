


#include "disasm.h"
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
	write(fd, champ->comment, ft_strlen(champ->name));
	write(fd, "\"\n", 2);
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
	filename[ft_strlen(filename) - 4] = 'D';
	filename[ft_strlen(filename) - 2] = '\0';
	printf("%s\n", filename);
	if ((fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0644)) < 0)
		read_error("Can't create file");
	write_name(fd, champ);
	write_comment(fd, champ);
	// write_code(fd, &champ);
	close(fd);
}