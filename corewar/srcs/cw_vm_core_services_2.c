/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_core_services_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 22:31:32 by gbrandon          #+#    #+#             */
/*   Updated: 2019/12/19 22:36:21 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char		**vm_cpy_regs(char **regs)
{
	char		**new_regs;
	int			i;

	new_regs = (char**)malloc(sizeof(char*) * (REG_NUMBER + 1));
	i = 0;
	while (i < REG_NUMBER)
	{
		new_regs[i] = (char*)ft_memalloc(sizeof(char) * (REG_SIZE + 1));
		new_regs[i] = ft_memcpy(new_regs[i], regs[i], REG_SIZE);
		i++;
	}
	new_regs[i] = NULL;
	return (new_regs);
}
