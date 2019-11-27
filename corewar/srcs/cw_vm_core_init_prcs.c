/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_core_init_prcs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 20:47:46 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/27 18:58:44 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_prcs	*add_prc(t_prcs *head, t_prcs *new)
{
	if (!new)
		return (NULL);
	new->next = head;
	head = new;
	return (head);
}

t_prcs		*cw_prcs_init(t_plr_ardata *plrdata)
{
	t_prcs			*prcs;
	t_prcs			*new_pr;
	t_plr_ardata	*pld;

	prcs = NULL;
	pld = plrdata;
	while(pld)
	{
		new_pr = init_process_start(pld->uid);
		add_prc(prcs, new_pr);
		pld = pld->next;
 	}
	return (prcs);
}
