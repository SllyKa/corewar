/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:59:51 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/21 18:12:21 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CW_STRUCTS_H
# define CW_STRUCTS_H

typedef struct	s_prcs
{
	char	carry;
	//int		cuid;
	int		pc;
	int		livecycle;
	int		waitcycle;
	int		curpos;
	int		nextop;
	char	**regs;
}				t_prcs;

typedef struct	s_arena
{
	int		lastlive;
	int		cyclen;
	int		liven;
	int		cycles_to_die;
	int		checkn;
	size_t	players;
	char	*field;
}				t_arena;

typedef struct	s_plr_ardata
{
	int					uid;
	char				*data;
	size_t				data_size;
	struct s_plr_ardata	*next;
}				t_plr_ardata;

#endif
