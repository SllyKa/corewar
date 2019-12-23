/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_start_avl_services.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 23:32:39 by gbrandon          #+#    #+#             */
/*   Updated: 2019/12/24 02:33:18 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "avlt.h"

void		*ins(void *data)
{
	int		*a;

	a = (int*)ft_memalloc(sizeof(int));
	*a = *((int*)data);
	return (a);
}

int			cmp(void *a, void *b)
{
	int		aa;
	int		bb;

	aa = *((int*)a);
	bb = *((int*)b);
	return (aa - bb);
}

static void	appt_tr(void *data)
{
	ft_printf("->%d\n", *((int*)data));
}

void		print_tree(t_avlt *tr)
{
	post_order(tr, appt_tr);
}

int			is_in_tree(t_avlt *root, int num)
{
	int		data;

	if (!root)
		return (0);
	data = *((int*)root->item);
	if (data == num)
		return (1);
	else if (data > num)
		return (is_in_tree(root->left, num));
	else if (data < num)
		return (is_in_tree(root->right, num));
	return (0);
}
