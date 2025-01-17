/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_core_constructors.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 14:43:50 by gbrandon          #+#    #+#             */
/*   Updated: 2020/01/09 20:53:44 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char			**init_regs(int r1)
{
	char	**new_regs;
	int		i;

	new_regs = (char**)malloc(sizeof(char*) * (REG_NUMBER + 1));
	i = 0;
	while (i < REG_NUMBER)
	{
		new_regs[i] = (char*)ft_memalloc(sizeof(char) * (REG_SIZE + 1));
		i++;
	}
	r1 *= -1;
	new_regs[0] = r_mov(new_regs[0], &r1, 4);
	new_regs[i] = NULL;
	return (new_regs);
}

t_prcs			*init_process_start(int r1, size_t pc)
{
	t_prcs		*new_prcs;

	new_prcs = (t_prcs*)malloc(sizeof(t_prcs));
	new_prcs->carry = 0;
	new_prcs->pc = pc;
	new_prcs->uid = r1;
	new_prcs->curop = 0;
	new_prcs->livecycle = -1;
	new_prcs->waitcycle = 0;
	new_prcs->nextop = 0;
	new_prcs->regs = init_regs(r1);
	new_prcs->next = NULL;
	return (new_prcs);
}

t_prcs			*init_process_cpy(t_prcs *src, size_t pc)
{
	t_prcs		*new_prcs;

	new_prcs = (t_prcs*)malloc(sizeof(t_prcs));
	new_prcs->carry = src->carry;
	new_prcs->pc = pc;
	new_prcs->uid = src->uid;
	new_prcs->curop = 0;
	new_prcs->livecycle = src->livecycle;
	new_prcs->waitcycle = 0;
	new_prcs->nextop = 0;
	new_prcs->regs = vm_cpy_regs(src->regs);
	new_prcs->next = NULL;
	return (new_prcs);
}

t_vm			*init_arena(t_plr_ardata *plrdata, size_t players,
unsigned char *field, unsigned char *vsfield)
{
	t_vm	*new_arena;

	new_arena = (t_vm*)malloc(sizeof(t_vm));
	new_arena->plrdata = plrdata;
	new_arena->checkn = 0;
	new_arena->cyclen = 0;
	new_arena->cycles_to_die = CYCLE_TO_DIE;
	new_arena->lastlive = 0;
	new_arena->liven = 0;
	new_arena->players = players;
	new_arena->field = field;
	new_arena->field_size = MEM_SIZE;
	new_arena->vsfield = vsfield;
	new_arena->prcs = NULL;
	return (new_arena);
}

t_args_data		*init_argsdata(size_t i, int fd, int f)
{
	t_args_data		*newardata;

	newardata = (t_args_data*)malloc(sizeof(t_args_data));
	newardata->root = NULL;
	newardata->plrdata = NULL;
	newardata->i = i;
	newardata->f = f;
	newardata->fd = fd;
	newardata->num = 0;
	return (newardata);
}
