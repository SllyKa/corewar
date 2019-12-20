/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_start_services.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 21:37:18 by gbrandon          #+#    #+#             */
/*   Updated: 2019/12/20 22:45:30 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_start.h"
#include "avlt.h"

void		cw_vm_errormsg(char *msg)
{
	if (!msg)
		ft_printf("\n%{red}Error:%{eoc} ");
	else
		ft_printf("\n%{red}Error:%{eoc}\t%s", msg);
}

void		check_and_passnum(int num)
{
	//will use avl)
}