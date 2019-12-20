/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 06:10:41 by gbrandon          #+#    #+#             */
/*   Updated: 2019/12/20 21:50:37 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	g_flags = 0;
int		g_verbf = 0;
int		g_memdmp = 0;

#include "corewar.h"
#include "corewar_start.h"

int		main(int argc, char **argv)
{
	cw_vm_start(argc, argv);
	return (0);
}