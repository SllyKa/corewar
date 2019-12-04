/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_core_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 11:11:17 by gbrandon          #+#    #+#             */
/*   Updated: 2019/12/04 18:44:22 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		live(t_vm *vm, t_prcs *prcs)
{
	unsigned char	*tdir;
	int				uid;
	int				r1;

	ft_printf("live!\n");

	tdir = vm_readb(vm->field, vm_add_address(prcs->pc, 1), DIR_SIZE);
	uid = *((int*)tdir);
	tdir = free_vm_readb(tdir);
	prcs->livecycle = vm->cyclen;
	tdir = r_get(prcs->regs[0]);
	r1 = *((int*)tdir);
	tdir = free_rget(tdir);
	if (uid == r1)
		cw_vm_core_upd_live(vm, r1);

	ft_printf("r1: %d\n", r1);
	ft_printf("u1: %d\n", uid);
	t_plr_ardata *tmp;
	tmp = vm->plrdata;
	while (tmp)
	{
		ft_printf("%d-live? %d\n", tmp->uid, tmp->liven);
		tmp = tmp->next;
	}
}