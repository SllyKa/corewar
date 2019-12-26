/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_core_services_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 22:31:32 by gbrandon          #+#    #+#             */
/*   Updated: 2019/12/26 19:05:18 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern char		g_flags;
extern int		g_verbf;

char		**vm_cpy_regs(char **regs)
{
	char		**new_regs;
	int			i;

	new_regs = (char**)malloc(sizeof(char*) * (REG_NUMBER + 1));
	i = 0;
	while (i < REG_NUMBER)
	{
		new_regs[i] = (char*)ft_memalloc(sizeof(char) * (REG_SIZE + 1));
		new_regs[i] = ft_memcpy(new_regs[i], regs[i], REG_SIZE);
		i++;
	}
	new_regs[i] = NULL;
	return (new_regs);
}

t_prcs		*cw_del_prcs(t_vm *vm, t_prcs *dl, t_prcs *prev)
{
	t_prcs		*temp;

	if (!dl)
		return (NULL);
	temp = dl;
	dl = dl->next;
	if (prev == NULL)
		vm->prcs = dl;
	else
		prev->next = dl;
	cw_free_tprcs(temp);
	return (dl);
}

static void	cw_vm_upd_live(t_vm *vm)
{
	t_plr_ardata	*pl;

	vm->liven = 0;
	pl = vm->plrdata;
	while (pl)
	{
		pl->liven = 0;
		pl = pl->next;
	}
}

void		cw_vm_cycle_set(t_vm *vm)
{
	if (vm->liven >= NBR_LIVE)
	{
		vm->cycles_to_die -= CYCLE_DELTA;
		vm->checkn = 0;
	}
	else
		(vm->checkn)++;
	if (vm->checkn == MAX_CHECKS)
	{
		vm->cycles_to_die -= CYCLE_DELTA;
		vm->checkn = 0;
	}
	cw_vm_upd_live(vm);
}

void		cw_vm_checkg_flag(void)
{
	if ((2 & g_flags) == 2)
	{
		g_flags |= 1;
		g_verbf |= 1;
	}
}
