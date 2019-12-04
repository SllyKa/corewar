/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_parse_plrdata.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:48:34 by gbrandon          #+#    #+#             */
/*   Updated: 2019/12/04 15:18:34 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_plr_ardata	*init_plrardata(int uid, char *data, size_t data_size)
{
	t_plr_ardata	*new_plrdata;

	new_plrdata = (t_plr_ardata*)malloc(sizeof(t_plr_ardata));
	new_plrdata->uid = uid;
	//new_plrdata->name = ...
	//new_plrdata->liven = 0;
	new_plrdata->data = data;
	new_plrdata->data_size = data_size;
	new_plrdata->next = NULL;
	return (new_plrdata);
}

t_plr_ardata		*add_plrdata(t_plr_ardata *head, int uid,
					char *data, size_t data_size)
{
	t_plr_ardata	*new_el;

	new_el = init_plrardata(uid, data, data_size);
	if (!head)
		head = new_el;
	else
	{
		new_el->next = head;
		head = new_el;
	}
	return (head);
}
