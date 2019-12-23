/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_start.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 19:08:03 by gbrandon          #+#    #+#             */
/*   Updated: 2019/12/24 02:43:29 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_START_H
# define COREWAR_START_H

# include <stdlib.h>
# include "op.h"
# include "libftprintf.h"
# include "cw_structs.h"
# include "avlt.h"

t_plr_ardata	*cw_vm_start(int argc, char **argv);
int				cw_vm_start_read_option(size_t argc, char **argv, size_t *i,
int *num);
void			cw_vm_errormsg(char *msg);
int				retneg_and_msg(char *msg);
int				checkn_and_pars(t_args_data *ardata);
int				cw_vm_setn(t_args_data *ardata);
void			swap_nodes(t_plr_ardata *a, t_plr_ardata *b);

void			*ins(void *data);
int				cmp(void *a, void *b);
void			print_tree(t_avlt *tr);
int				is_in_tree(t_avlt *root, int num);

void			cw_vm_introduce_players(t_plr_ardata *plrdata);
void			cw_vm_won_player(t_vm *vm);

t_args_data		*init_argsdata(size_t i, int fd, int f);
void			*cw_free_targsdata(t_args_data *ardata, char prm);

#endif
