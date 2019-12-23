/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_start_check_pass_num.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 23:37:04 by gbrandon          #+#    #+#             */
/*   Updated: 2019/12/24 02:35:33 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_start.h"
#include "corewar.h"

static void			cw_vm_sortl(t_plr_ardata *ardata)
{
	t_plr_ardata	*plrdata;
	t_plr_ardata	*temp;
	char			f;

	f = 1;
	temp = NULL;
	while (f)
	{
		f = 0;
		plrdata = ardata;
		while (plrdata->next != temp)
		{
			if (plrdata->uid > plrdata->next->uid)
			{
				swap_nodes(plrdata, plrdata->next);
				f = 1;
			}
			plrdata = plrdata->next;
		}
		temp = plrdata;
	}
}

static int			cw_vm_check_max(t_args_data *ardata, int pnum)
{
	t_plr_ardata	*pdata;

	pdata = ardata->plrdata;
	while (pdata)
	{
		if (pdata->uid > pnum)
			return (retneg_and_msg("Number is too big.\n"));
		pdata = pdata->next;
	}
	return (1);
}

int					cw_vm_setn(t_args_data *ardata)
{
	t_plr_ardata	*pdata;
	size_t			plrnum;
	size_t			numpul;

	plrnum = 0;
	numpul = 1;
	pdata = ardata->plrdata;
	while (pdata)
	{
		if (pdata->uid == -1)
		{
			while (is_in_tree(ardata->root, numpul))
				numpul++;
			pdata->uid = numpul;
			numpul++;
		}
		plrnum++;
		pdata = pdata->next;
	}
	if (plrnum > MAX_PLAYERS)
		return (retneg_and_msg("Too many champions.\n"));
	if (cw_vm_check_max(ardata, plrnum) < 0)
		return (-1);
	cw_vm_sortl(ardata->plrdata);
	return (1);
}

static int			check_num(t_args_data *ardata)
{
	if (ardata->f == 2)
	{
		if (ardata->num <= 0)
			return (retneg_and_msg("Invalid player number.\n"));
		if (is_in_tree(ardata->root, ardata->num))
			return (retneg_and_msg("This player number already exists.\n"));
		if (ardata->num > MAX_PLAYERS)
			return (retneg_and_msg("Too big player number.\n"));
		add_node(&(ardata->root), &(ardata->num), cmp, ins);
		ardata->f = 0;
	}
	else
		ardata->num = -1;
	return (1);
}

int					checkn_and_pars(t_args_data *ardata)
{
	if (check_num(ardata) < 0)
	{
		close(ardata->fd);
		return (-1);
	}
	parse_champ(&(ardata->plrdata), ardata->num, ardata->fd);
	close(ardata->fd);
	return (1);
}
