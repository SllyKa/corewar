/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_start.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 19:08:03 by gbrandon          #+#    #+#             */
/*   Updated: 2019/12/20 21:49:59 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_START_H
# define COREWAR_START_H

# include <stdlib.h>
# include "op.h"
# include "libftprintf.h"
# include "cw_structs.h"

t_plr_ardata	*cw_vm_start(int argc, char **argv);
int				cw_vm_start_read_option(size_t argc, char **argv, size_t i,
int *num);
void			cw_vm_errormsg(char *msg);

#endif