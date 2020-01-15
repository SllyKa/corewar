#ifndef DISASM_H
# define DISASM_H

# include "libft.h"
# include <fcntl.h>
# include "op.h"

#include "stdio.h"


# define CODE_REG_SIZE	1
typedef struct	s_plr_ardata
{
	int					uid;
	char				*name;
	char				*comment;
	char				*data;
	size_t				liven;
	size_t				data_size;
	struct s_plr_ardata	*next;
}				t_plr_ardata;



typedef struct	s_op
{
	char			*name;
	unsigned char	argnum;
	t_arg_type		argtype[3];
	unsigned char	opcode;
	int				wait;
	char			*descript;
	char			istypeb;
	char			isadress;
	void			*f_ptr;
}				t_op;


void		read_error(char *msg);


void disassembler(char *filename);


void				parse_champ(t_plr_ardata **plr, int champ_id, int fd);
void free_champ(t_plr_ardata *plr);

void				error_exit(char *str);
void	read_champ_name(t_plr_ardata *plr, int fd);
void	read_code_comment(t_plr_ardata *plr, int fd);
void	read_zero_bytes(int fd);
void	read_code_size(t_plr_ardata *plr, int fd);
void	read_champ_code(t_plr_ardata *plr, int fd);
int				check_opsign(char *code);


int				ops_read_treg(char *field, size_t addr);
int				ops_read_tdir(char *field, size_t addr, size_t size);
int				ops_read_tind(char *field, size_t addr);
unsigned char	vm_core_ops_argn_type(unsigned char typebyte, size_t argn);




# endif