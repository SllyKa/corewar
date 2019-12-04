/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 12:21:52 by gbrandon          #+#    #+#             */
/*   Updated: 2019/12/04 15:59:18 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <stdlib.h>
# include "op.h"
# include "libftprintf.h"
# include "cw_structs.h"

void			live(t_vm *vm, t_prcs *prcs);


char			**init_regs(int r1);
t_prcs			*init_process_start(int r1, size_t pc);
t_prcs			*init_process_cpy(t_prcs *src);
t_vm			*init_arena(size_t players, unsigned char *field);

t_vm			*cw_arena_init(t_plr_ardata *chmp_init);
t_prcs			*cw_prcs_init(t_vm *vm, t_plr_ardata *plrdata);
int				cw_fight(t_vm *vm);
void			check_opsign(t_vm *vm, t_prcs *prc);

char			*r_mov(char *reg, void *data, size_t size);
unsigned char	*r_get(char *reg);
void			*free_rget(unsigned char *val);
int				r_geti(char *reg);

unsigned char 	deref_pntr(unsigned char *field, size_t pntr);
size_t			vm_add_address(size_t pc, int offset);
int				chk_opcode(unsigned char opcode);
void			cw_vm_core_upd_live(t_vm *vm, int uid);

unsigned char	*vm_readb(unsigned char *field, size_t pos, size_t size);
void			*free_vm_readb(unsigned char *bt);

t_plr_ardata	*add_plrdata(t_plr_ardata *head, int uid,
					char *data, size_t data_size);

void			cw_vm_memdump(t_vm *arena);

#endif