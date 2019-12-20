/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 06:12:39 by gbrandon          #+#    #+#             */
/*   Updated: 2019/12/20 22:11:51 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include "corewar_start.h"

static void		cw_vm_usage(void)
{
	ft_printf("\n%{green}Usage:%{eoc} ./corewar [-dump N -v N | -g] [-a] [[-n number] champ1.cor] ...\n\n");
	ft_printf("\t%{blue}-a%{eoc}\t: Prints output from aff (disabled by default)\n");
	ft_printf("\t%{blue}-n    N%{eoc}\t: Sets number to the Player (assigns by ascending order by default)\n");
	ft_printf("\t%{blue}-dump N%{eoc}\t: Dump memory after N cycles and exits\n");
	ft_printf("\t%{blue}-v    N%{eoc}\t: Verbosity levels. Can be combined\n");
	ft_printf("\t\t\t- 0 :\n");
	ft_printf("\t\t\t- 1 :\n");
	ft_printf("\t\t\t- 2 :\n");
	ft_printf("\t\t\t- 4 :\n");
	ft_printf("\t\t\t- 8 :\n");
	ft_printf("\t\t\t- 16:\n");
	ft_printf("**** NCURSES OUTPUT MODE *************************************\n");
	ft_printf("\t%{blue}-g%{eoc}\t: Ncurses(graphic) output mode\n");
	ft_printf("**************************************************************\n");
}

static int			cw_vm_read_fname(char **argv, size_t i, int *fd)
{
	if ((*fd = open(argv[i], O_RDONLY)) < 0)
	{
		cw_vm_errormsg(argv[i]);
		perror(" ");
		// should free all t_plr_data here;
		return (-1);
	}
	return (0);
}

static t_plr_ardata	*read_args(size_t argc, char **argv)
{
	t_plr_ardata	*plrdata;
	size_t			i;
	int				fd;
	int				num;

	i = 1;
	plrdata = NULL;
	while (i < argc)
	{
		if (argv[i][0] == '-')
		{
			if (cw_vm_start_read_option(argc, argv, i, &num) < 0)
			{
				// should free all t_plr_data here;
				return (NULL);
			}
		}
		else
		{
			if (cw_vm_read_fname(argv, i, &fd) < 0)
			{
				// should free all t_plr_data here;
				return (NULL);
			}
		}
		// pass num to parser
		i++;
	}
	return (NULL);
}

t_plr_ardata		*cw_vm_start(int argc, char **argv)
{
	if (argc <= 1)
	{
		cw_vm_usage();
		return (NULL);
	}
	read_args(argc, argv);
	
	return (NULL);
}