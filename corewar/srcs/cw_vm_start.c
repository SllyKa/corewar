/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 06:12:39 by gbrandon          #+#    #+#             */
/*   Updated: 2019/12/22 03:00:48 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include "corewar_start.h"

static void			cw_vm_usage(void)
{
	ft_printf("\n%{green}Usage:%{eoc} ./corewar [-dump N -v N | -g] [-a] \
[[-n number] champ1.cor] ...\n\n");
	ft_printf("\t%{blue}-a%{eoc}\t: Prints output from aff (disabled by d\
efault)\n");
	ft_printf("\t%{blue}-n    N%{eoc}\t: Sets number to the Player (assig\
ns by ascending order by default)\n");
	ft_printf("\t%{blue}-dump N%{eoc}\t: Dump memory after N cycles and e\
xits\n");
	ft_printf("\t%{blue}-v    N%{eoc}\t: Verbosity levels. Can be combine\
d\n");
	ft_printf("\t\t\t- 0 :\n");
	ft_printf("\t\t\t- 1 :\n");
	ft_printf("\t\t\t- 2 :\n");
	ft_printf("\t\t\t- 4 :\n");
	ft_printf("\t\t\t- 8 :\n");
	ft_printf("\t\t\t- 16:\n");
	ft_printf("**** NCURSES OUTPUT MODE **********************************\n");
	ft_printf("\t%{blue}-g%{eoc}\t: Ncurses(graphic) output mode\n");
	ft_printf("***********************************************************\n");
}

static int			cw_vm_readf_and_pars(char **argv, t_args_data *ardata)
{
	if ((ardata->fd = open(argv[ardata->i], O_RDONLY)) < 0)
	{
		cw_vm_errormsg(argv[ardata->i]);
		perror(" ");
		return (-1);
	}
	if (checkn_and_pars(ardata) < 0)
		return (-1);
	return (0);
}

static t_plr_ardata	*retnull_and_free(t_args_data *ardata)
{
	ardata = cw_free_targsdata(ardata, 0);
	return (NULL);
}

static t_plr_ardata	*read_args(size_t argc, char **argv)
{
	t_args_data		*ardata;

	ardata = init_argsdata(1, -1, 0);
	while (ardata->i < argc)
	{
		ardata->fd = -1;
		if (argv[ardata->i][0] == '-')
		{
			if ((ardata->f = cw_vm_start_read_option(argc,
			argv, &(ardata->i), &(ardata->num))) < 0)
				return (retnull_and_free(ardata));
		}
		else
		{
			if (cw_vm_readf_and_pars(argv, ardata) < 0)
				return (retnull_and_free(ardata));
		}
		(ardata->i)++;
	}
	if (ardata->plrdata == NULL)
	{
		cw_vm_errormsg("There are no champions.\n");
		return (retnull_and_free(ardata));
	}
	return (cw_free_targsdata(ardata, 1));
}

t_plr_ardata		*cw_vm_start(int argc, char **argv)
{
	t_plr_ardata		*plrdata;

	if (argc <= 1)
	{
		cw_vm_usage();
		return (NULL);
	}
	if (!(plrdata = read_args(argc, argv)))
		return (NULL);
	return (plrdata);
}
