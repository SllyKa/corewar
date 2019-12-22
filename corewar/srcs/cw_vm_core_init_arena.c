/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_core_init_arena.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:34:30 by gbrandon          #+#    #+#             */
/*   Updated: 2019/12/22 10:24:13 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static size_t			core_player_cntr(t_plr_ardata *chmpinit)
{
	size_t	cntr;

	cntr = 0;
	while (chmpinit)
	{
		chmpinit = chmpinit->next;
		cntr++;
	}
	return (cntr);
}

static unsigned char	*init_field(t_plr_ardata *chmp_init, size_t players)
{
	unsigned char	*arena_f;
	unsigned char	*arena_head;
	size_t			i;

	i = 0;
	arena_f = ft_memalloc(MEM_SIZE);
	arena_head = arena_f;
	while (i < players)
	{
		ft_memcpy(arena_f, chmp_init->data, chmp_init->data_size);
		arena_f = arena_f + (MEM_SIZE / players);
		chmp_init = chmp_init->next;
		i++;
	}
	return (arena_head);
}

static unsigned char	*init_vsfield(t_plr_ardata *chmp_init, size_t players)
{
	unsigned char	*arena_f;
	unsigned char	*arena_head;
	size_t			i;

	i = 0;
	arena_f = ft_memalloc(MEM_SIZE);
	arena_head = arena_f;
	while (i < players)
	{
		ft_memset(arena_f, (unsigned char)(chmp_init->uid), chmp_init->data_size);
		arena_f = arena_f + (MEM_SIZE / players);
		chmp_init = chmp_init->next;
		i++;
	}
	return (arena_head);
}

t_vm					*cw_arena_init(t_plr_ardata *chmp_init)
{
	unsigned char			*arena_f;
	unsigned char			*vsarena;
	size_t					players;
	t_vm					*vm;

	players = core_player_cntr(chmp_init);
	arena_f = init_field(chmp_init, players);
	vsarena = init_vsfield(chmp_init, players);
	vm = init_arena(chmp_init, players, arena_f, vsarena);
	return (vm);
}
