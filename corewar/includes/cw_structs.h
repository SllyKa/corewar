/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:59:51 by gbrandon          #+#    #+#             */
/*   Updated: 2019/12/04 15:31:51 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CW_STRUCTS_H
# define CW_STRUCTS_H

#include "libftprintf.h"

typedef struct	s_plr_ardata
{
	int					uid;
	char				*name;
	char				*data;
	size_t				liven;
	size_t				data_size;
	struct s_plr_ardata	*next;
}				t_plr_ardata;

typedef struct	s_prcs
{
	char			carry;
	size_t			pc;
	int				livecycle;
	int				waitcycle;
	unsigned char	curop;
	int				nextop;
	char			**regs;
	struct s_prcs	*next;	
}				t_prcs;

typedef struct	s_vm
{
	int				lastlive;
	t_plr_ardata	*plrdata;
	size_t			cyclen;
	int				liven;
	int				cycles_to_die;
	int				checkn;
	size_t			players;
	unsigned char	*field;
	size_t			field_size;
	t_prcs			*prcs;
}				t_vm;

typedef struct	s_op
{
	char			*name;
	unsigned char	argnum;
	t_arg_type		argtype[3];
	unsigned char	opcode;
	int				wait;
	char			*descript;
	char			usecarry;
	char			isadress;
}				t_op;

#endif
