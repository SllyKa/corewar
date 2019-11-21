/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:34:30 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/21 18:07:27 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static size_t	core_player_cntr(t_plr_ardata *chmpinit)
{
	size_t	cntr;

	cntr = 0;
	while(chmpinit)
	{
		chmpinit = chmpinit->next;
		cntr++;
	}
	return (cntr);
}

static char		*init_field(t_plr_ardata *chmp_init, size_t players)
{
	char	*arena_f;
	char	*arena_head;
	size_t	i;

	i = 0;
	arena_f = ft_memalloc(MEM_SIZE);
	arena_head = arena_f;
	while (i < players)
	{
		ft_memcpy(arena_f, chmp_init->data, chmp_init->data_size);
		arena_f = arena_f + (MEM_SIZE / players);
		i++;
	}
	return(arena_head);
}

int				cw_arena_init(t_plr_ardata *chmp_init)
{
	char			*arena_f;
	size_t			players;

	players = core_player_cntr(chmp_init);
	arena_f = init_field(chmp_init, players);
	return (0);
}
