/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 12:21:52 by gbrandon          #+#    #+#             */
/*   Updated: 2019/12/18 22:06:52 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <stdlib.h>
# include "op.h"
# include "libftprintf.h"
# include "cw_structs.h"

#define	CODE_REG_SIZE	1

void			live(t_vm *vm, t_prcs *prcs);
void			ld(t_vm *vm, t_prcs *prcs);
void			st(t_vm *vm, t_prcs *prcs);
void			add(t_vm *vm, t_prcs *prcs);
void			sub(t_vm *vm, t_prcs *prcs);


char			**init_regs(int r1);
t_prcs			*init_process_start(int r1, size_t pc);
t_prcs			*init_process_cpy(t_prcs *src);
t_vm			*init_arena(t_plr_ardata *plrdata, size_t players,
unsigned char *field);

t_vm			*cw_arena_init(t_plr_ardata *chmp_init);
t_prcs			*cw_prcs_init(t_vm *vm);
int				cw_fight(t_vm *vm);
void			check_opsign(t_vm *vm, t_prcs *prc);
int				chk_reg_valid(t_vm *vm, t_prcs *prcs, unsigned char opcode,
unsigned char typebyte);
unsigned char	typebyte_to_arg_type(unsigned char arg);

char			*r_mov(char *reg, void *data, size_t size);
unsigned char	*r_get(char *reg);
void			*free_rget(unsigned char *val);
void			reverse_reg(unsigned char *reg);
int				r_geti(char *reg);

unsigned char 	deref_pntr(unsigned char *field, size_t pntr);
size_t			vm_add_address(size_t pc, int offset);
int				vm_btoi(unsigned char *bytes, size_t size);
int				chk_opcode(unsigned char opcode);
void			cw_vm_core_upd_live(t_vm *vm, int uid);
unsigned char	vm_core_ops_argn_type(unsigned char typebyte, size_t argn);

int				ops_read_tdir(unsigned char *field, size_t addr, size_t size);
int				ops_read_treg(unsigned char *field, size_t addr);
int				ops_read_tind(unsigned char *field, size_t addr);
unsigned char	*vm_core_add(unsigned char *val1, unsigned char *val2, 
int size1, int *size2);

unsigned char	*vm_readb(unsigned char *field, size_t pos, size_t size);
void			vm_writeb(unsigned char *field, size_t adrs, void *data,
size_t size);
void			*free_vm_readb(unsigned char *bt);

void			error_exit(char *str);
void			read_champ_name(t_plr_ardata *plr, int fd);
void			read_code_comment(int fd);
void			read_zero_bytes(int fd);
void			read_code_size(t_plr_ardata *plr, int fd);
void			read_champ_code(t_plr_ardata *plr, int fd);

void			parse_champ(t_plr_ardata **plr, int champ_id, int fd);




void			cw_vm_memdump(t_vm *arena);

#endif