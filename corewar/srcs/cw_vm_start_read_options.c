/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_start_read_options.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 21:15:08 by gbrandon          #+#    #+#             */
/*   Updated: 2020/01/09 18:22:10 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_start.h"

extern char		g_flags;
extern int		g_verbf;
extern int		g_memdmp;

static int	check_next_arg(size_t argc, char **argv, size_t *i, int *num)
{
	int			er_code;

	er_code = 0;
	if (*i + 1 < argc)
	{
		*num = ft_satoi(argv[*i + 1], &er_code);
		if (er_code < 0)
			return (retneg_and_msg("Invalid argument for option.\n"));
	}
	else
		return (retneg_and_msg("No argument for option.\n"));
	(*i)++;
	return (1);
}

int			cw_vm_start_read_option(size_t argc, char **argv, size_t *i,
int *num)
{
	if (argv[*i][1] != '\0')
	{
		if (argv[*i][1] == 'a' && argv[*i][2] == '\0')
			g_flags = g_flags | 1;
		else if (argv[*i][1] == 'g' && argv[*i][2] == '\0')
			g_flags = g_flags | 2;
		else if (argv[*i][1] == 'o' && argv[*i][2] == '\0')
			g_flags = g_flags | 4;
		else if (argv[*i][1] == 'n' && argv[*i][2] == '\0' &&
		(check_next_arg(argc, argv, i, num) > 0))
			return (2);
		else if (argv[*i][1] == 'd' && !ft_strcmp("-dump", argv[*i]) &&
		(check_next_arg(argc, argv, i, &g_memdmp) > 0))
			return (1);
		else if (argv[*i][1] == 'v' && argv[*i][2] == '\0' &&
		(check_next_arg(argc, argv, i, &g_verbf) > 0))
			return (1);
		else
			return (retneg_and_msg("Unknown option.\n"));
	}
	else
		return (retneg_and_msg("Unknown option.\n"));
	return (1);
}
