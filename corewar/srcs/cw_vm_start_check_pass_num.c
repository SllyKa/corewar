/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_start_check_pass_num.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 23:37:04 by gbrandon          #+#    #+#             */
/*   Updated: 2019/12/22 01:49:16 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_start.h"

static int	check_num(t_args_data *ardata)
{
	static int 	plrnum = 1;

	if (ardata->f == 2)
	{
		if (ardata->num <= 0)
			return (retneg_and_msg("Invalid player number.\n"));
		if (is_in_tree(ardata->root, ardata->num))
			return (retneg_and_msg("This player number already exists.\n"));
		add_node(&(ardata->root), &(ardata->num), cmp, ins);
		ardata->f = 0;
	}
	else
	{
		while (is_in_tree(ardata->root, plrnum))
			plrnum++;
		add_node(&(ardata->root), &plrnum, cmp, ins);
		ardata->num = plrnum;
		plrnum++;
	}
	return (1);
}

int			checkn_and_pars(t_args_data *ardata)
{
	if (check_num(ardata) < 0)
	{
		close(ardata->fd);
		return (-1);
	}
	// ardata->plrdata = parse();
	close(ardata->fd);
	return (1);
}