/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_start_services.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 21:37:18 by gbrandon          #+#    #+#             */
/*   Updated: 2019/12/24 02:34:36 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_start.h"
#include "avlt.h"

static void	*cw_free_tree(t_avlt *root)
{
	if (!root)
		return (NULL);
	root->left = cw_free_tree(root->left);
	root->right = cw_free_tree(root->right);
	if (root->item)
	{
		free(root->item);
		root->item = NULL;
	}
	free(root);
	return (NULL);
}

void		*cw_free_targsdata(t_args_data *ardata, char prm)
{
	t_plr_ardata	*plrdata;

	if (!ardata)
		return (NULL);
	plrdata = ardata->plrdata;
	if (ardata->root)
		ardata->root = cw_free_tree(ardata->root);
	if (ardata->plrdata && !prm)
		ardata->plrdata = cw_free_all_tplrardata(ardata->plrdata);
	free(ardata);
	if (prm)
		return (plrdata);
	return (NULL);
}

void		cw_vm_errormsg(char *msg)
{
	if (!msg)
		ft_printf("\n%{red}Error:%{eoc} ");
	else
		ft_printf("\n%{red}Error:%{eoc}\t%s", msg);
}

int			retneg_and_msg(char *msg)
{
	cw_vm_errormsg(msg);
	return (-1);
}

void		swap_nodes(t_plr_ardata *a, t_plr_ardata *b)
{
	t_plr_ardata	*temp;

	temp = (t_plr_ardata*)malloc(sizeof(t_plr_ardata));
	// add copy commentary
	temp->uid = a->uid;
	temp->name = a->name;
	temp->data = a->data;
	temp->data_size = a->data_size;
	a->uid = b->uid;
	a->name = b->name;
	a->data = b->data;
	a->data_size = b->data_size;
	b->uid = temp->uid;
	b->name = temp->name;
	b->data = temp->data;
	b->data_size = temp->data_size;
	free(temp);
}
