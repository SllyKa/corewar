/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_wm_core_memdump.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:12:25 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/26 18:18:40 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cw_vm_memdump(t_vm *arena)
{
	size_t				i;
	size_t				oct_num;
	unsigned char		*arena_f;

	i = 0;
	oct_num = 32;
	arena_f = arena->field;
	while (i < arena->field_size)
	{
		if ((i == 0) || (i % 32 == 0))
			ft_printf("\n0x%0.4x : ", i);
		ft_printf("%.2x", *arena_f);
		arena_f++;
		i++;
		if (i % 32 != 0)
			ft_printf(" ");
	}
	ft_printf("\n");
}