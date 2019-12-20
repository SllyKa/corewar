/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_core_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 03:50:21 by gbrandon          #+#    #+#             */
/*   Updated: 2019/12/20 03:59:08 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_prcs		*cw_free_tprcs(t_prcs *prc)
{
	if (!prc)
		return (NULL);
	prc->regs = cw_free_regs(prc->regs);
	free(prc);
	return (NULL);
}

char		**cw_free_regs(char **regs)
{
	char	**regs_head;

	if (!regs)
		return (NULL);
		regs_head = regs;
	while(*regs_head)
	{
		free(*regs_head);
		regs_head++;
	}
	free(regs);
	return (NULL);
}