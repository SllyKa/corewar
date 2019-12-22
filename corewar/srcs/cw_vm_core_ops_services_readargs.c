/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_core_ops_services_readargs.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 22:07:32 by gbrandon          #+#    #+#             */
/*   Updated: 2019/12/22 07:13:47 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				ops_read_tdir(unsigned char *field, size_t addr, size_t size)
{
	unsigned char	*tdir;
	int				res;

	tdir = vm_readb(field, addr, size);
	res = vm_btoi(tdir, size);
	tdir = free_vm_readb(tdir);
	return (res);
}

int				ops_read_treg(unsigned char *field, size_t addr)
{
	unsigned char	*treg;
	int				res;

	treg = vm_readb(field, addr, CODE_REG_SIZE);
	res = vm_btoi(treg, CODE_REG_SIZE);
	free_vm_readb(treg);
	return (res);
}

int				ops_read_tind(unsigned char *field, size_t addr)
{
	unsigned char	*tind;
	int				resoffst;

	tind = vm_readb(field, addr, IND_SIZE);
	resoffst = vm_btoi(tind, IND_SIZE);
	free_vm_readb(tind);
	resoffst = resoffst % IDX_MOD;
	return (resoffst);
}
