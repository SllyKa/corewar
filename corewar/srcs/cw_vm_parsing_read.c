/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_parsing_read.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 18:36:46 by bjesse            #+#    #+#             */
/*   Updated: 2019/12/21 18:36:48 by bjesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	read_champ_name(t_plr_ardata *plr, int fd)
{
	if (read(fd, plr->name, PROG_NAME_LENGTH) != PROG_NAME_LENGTH)
		error_exit("bad name!\n");
	plr->name[PROG_NAME_LENGTH] = '\0';
}

void	read_code_comment(int fd)
{
	char	buff[COMMENT_LENGTH];

	if (read(fd, buff, COMMENT_LENGTH) != COMMENT_LENGTH)
		error_exit("bad comment!\n");
}

void	read_zero_bytes(int fd)
{
	unsigned char	buff[4];
	int				i;

	i = 0;
	if (read(fd, buff, 4) != 4)
		error_exit("bad null value!\n");
	while (i < 4)
	{
		if (buff[i])
			error_exit("bad null value!\n");
		i++;
	}
}

void	read_code_size(t_plr_ardata *plr, int fd)
{
	unsigned char	buff[4];
	int				i;

	i = 0;
	if (read(fd, buff, 4) != 4)
		error_exit("bad code size!\n");
	plr->data_size = 0;
	while (i < 4)
	{
		plr->data_size = plr->data_size * 256 + buff[i];
		i++;
	}
	if (plr->data_size > CHAMP_MAX_SIZE)
		error_exit("Exe code too big!\n");
}

void	read_champ_code(t_plr_ardata *plr, int fd)
{
	char	buff[1];

	plr->data = (char*)malloc(plr->data_size * sizeof(char));
	if (read(fd, plr->data, plr->data_size) != (long long)plr->data_size)
		error_exit("Wrong exe code: too small!\n");
	if (read(fd, buff, 1) > 0)
		error_exit("Wrong exe code: too big!\n");
}
