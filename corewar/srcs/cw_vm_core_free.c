/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_core_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 03:50:21 by gbrandon          #+#    #+#             */
/*   Updated: 2019/12/22 07:08:39 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_vm			*cw_free_vm(t_vm *vm)
{
	if (!vm)
		return (NULL);
	if (vm->plrdata)
		vm->plrdata = cw_free_all_tplrardata(vm->plrdata);
	if (vm->field)
		free(vm->field);
	if (vm->prcs)
		cw_free_all_tprcs(vm->prcs);
	free(vm);
	return (NULL);
}

t_plr_ardata	*cw_free_all_tplrardata(t_plr_ardata *plrdata)
{
	t_plr_ardata	*temp;

	if (!plrdata)
		return (NULL);
	while (plrdata)
	{
		temp = plrdata;
		if (temp->name)
			free(temp->name);
		if (temp->data)
			free(temp->data);
		free(temp);
		plrdata = plrdata->next;
	}
	return (NULL);
}

t_prcs			*cw_free_tprcs(t_prcs *prc)
{
	if (!prc)
		return (NULL);
	prc->regs = cw_free_regs(prc->regs);
	free(prc);
	return (NULL);
}

t_prcs			*cw_free_all_tprcs(t_prcs *prcs_head)
{
	t_prcs		*temp;

	if (!prcs_head)
		return (NULL);
	while (prcs_head)
	{
		temp = prcs_head;
		prcs_head = prcs_head->next;
		cw_free_tprcs(temp);
	}
	return (NULL);
}

char			**cw_free_regs(char **regs)
{
	char	**regs_head;

	if (!regs)
		return (NULL);
	regs_head = regs;
	while (*regs_head)
	{
		free(*regs_head);
		regs_head++;
	}
	free(regs);
	return (NULL);
}
