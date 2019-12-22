/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_hi_players.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 06:15:17 by gbrandon          #+#    #+#             */
/*   Updated: 2019/12/22 11:20:39 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_start.h"

static size_t	cw_vm_plrs_countt(t_plr_ardata *pldata)
{
	size_t			maxplrs;
	t_plr_ardata	*pdata;

	pdata = pldata;
	maxplrs = 0;
	while (pdata)
	{
		maxplrs++;
		pdata = pdata->next;
	}
	return (maxplrs);
}

static void		intr_service(t_plr_ardata *pdata, int *uid, size_t *i)
{
	ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%%s\") !\n"
	, pdata->uid, pdata->data_size, pdata->name
	/*, pdata->comment*/);
	(*uid)++;
	(*i)++;
}

void			cw_vm_introduce_players(t_plr_ardata *plrdata)
{
	t_plr_ardata	*pdata;
	int				minuid;
	size_t			maxplrs;
	size_t			i;

	i = 0;
	minuid = 1;
	maxplrs = cw_vm_plrs_countt(plrdata);
	ft_printf("Introducing contestants...\n");
	while (i < maxplrs)
	{
		pdata = plrdata;
		while (pdata)
		{
			if (minuid == pdata->uid)
			{
				intr_service(pdata, &minuid, &i);
				break ;
			}
			pdata = pdata->next;
		}
		if (!pdata)
			minuid++;
	}
}

void			cw_vm_won_player(t_vm *vm)
{
	t_plr_ardata	*pdata;

	pdata = vm->plrdata;
	while (pdata)
	{
		if (pdata->uid == vm->lastlive * -1)
			ft_printf("Player %d (%s) won\n", pdata->uid, pdata->name);
		pdata = pdata->next;
	}
}
