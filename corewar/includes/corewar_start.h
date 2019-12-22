/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_start.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 19:08:03 by gbrandon          #+#    #+#             */
/*   Updated: 2019/12/22 02:38:31 by gbrandon         ###   ########.fr       */
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

void			*ins(void *data);
int				cmp(void *a, void *b);
void			print_tree(t_avlt *tr);
int				is_in_tree(t_avlt *root, int num);

t_args_data		*init_argsdata(size_t i, int fd, int f);
void			*cw_free_targsdata(t_args_data *ardata, char prm);


#endif