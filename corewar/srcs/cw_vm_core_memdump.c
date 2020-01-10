/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_core_memdump.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:12:25 by gbrandon          #+#    #+#             */
/*   Updated: 2020/01/09 18:33:23 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern int	g_flags;

static void	cw_vm_memdump_origin_print(t_vm *vm)
{
	size_t				i;
	unsigned char		*arena_f;

	i = 0;
	arena_f = vm->field;
	while (i < vm->field_size)
	{
		if ((i != 0) && (i % 64 == 0))
			ft_printf("\n");
		if ((i == 0) || (i % 64 == 0))
			ft_printf("0x%0.4x : ", i);
		ft_printf("%.2x", *arena_f);
		arena_f++;
		i++;
		ft_printf(" ");
	}
	ft_printf("\n");
}

static void	cw_vm_memdump_print(t_vm *vm, size_t octnum)
{
	size_t				i;
	unsigned char		*arena_f;

	i = 0;
	arena_f = vm->field;
	while (i < vm->field_size)
	{
		if ((i == 0) || (i % octnum == 0))
			ft_printf("\n0x%0.4x : ", i);
		ft_printf("%.2x", *arena_f);
		arena_f++;
		i++;
		if (i % octnum != 0)
			ft_printf(" ");
	}
	ft_printf("\n");
}

void		cw_vm_memdump(t_vm *vm)
{
	if ((4 & g_flags) != 4)
		cw_vm_memdump_print(vm, 32);
	else
		cw_vm_memdump_origin_print(vm);
}
