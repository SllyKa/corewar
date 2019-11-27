/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 12:21:52 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/27 19:23:24 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <stdlib.h>
# include "op.h"
# include "libftprintf.h"
# include "cw_structs.h"

char			**init_regs(int r1);
t_prcs			*init_process_start(int r1);
t_prcs			*init_process_cpy(t_prcs *src);
t_vm			*init_arena(size_t players, unsigned char *field);

t_vm			*cw_arena_init(t_plr_ardata *chmp_init);
t_prcs			*cw_prcs_init(t_plr_ardata *plrdata);

char			*r_mov(char *reg, void *data, size_t size);

t_plr_ardata	*add_plrdata(t_plr_ardata *head, int uid,
					char *data, size_t data_size);

void			cw_vm_memdump(t_vm *arena);

#endif