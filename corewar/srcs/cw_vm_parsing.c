/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 18:36:42 by bjesse            #+#    #+#             */
/*   Updated: 2019/12/21 18:36:43 by bjesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				error_exit(char *str)
{
	ft_printf("%s", str);
	exit(1);
}

static t_plr_ardata	*create_plrdata(void)
{
	t_plr_ardata	*new_plrdata;

	new_plrdata = (t_plr_ardata*)malloc(sizeof(t_plr_ardata));
	new_plrdata->name = (char*)malloc((PROG_NAME_LENGTH + 1) * sizeof(char));
	new_plrdata->liven = 0;
	new_plrdata->next = NULL;
	return (new_plrdata);
}

void				check_magick_number(int fd)
{
	char	buff[5];
	char	magic_num[4];
	int		i;
	long	magic;

	if (read(fd, buff, 4) != 4)
		error_exit("bad magic num!\n");
	buff[4] = 0;
	i = 3;
	magic = COREWAR_EXEC_MAGIC;
	while (i >= 0)
	{
		magic_num[i] = magic % 256;
		magic /= 256;
		i--;
	}
	if (buff[0] == magic_num[0] && !ft_strcmp(buff + 1, magic_num + 1))
		return ;
	error_exit("bad magic num!\n");
}

void				add_plr_to_list(t_plr_ardata **plr, t_plr_ardata *new_plr)
{
	t_plr_ardata *now_plr;

	if (!*plr)
	{
		*plr = new_plr;
		return ;
	}
	now_plr = *plr;
	while (now_plr->next)
		now_plr = now_plr->next;
	now_plr->next = new_plr;
}

void				parse_champ(t_plr_ardata **plr, int champ_id, int fd)
{
	t_plr_ardata *new_plr;

	check_magick_number(fd);
	new_plr = create_plrardata();
	new_plr->uid = champ_id;
	read_champ_name(new_plr, fd);
	read_zero_bytes(fd);
	read_code_size(new_plr, fd);
	read_code_comment(fd);
	read_zero_bytes(fd);
	read_champ_code(new_plr, fd);
	add_plr_to_list(plr, new_plr);
}
