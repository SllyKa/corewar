/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 15:09:35 by fsinged           #+#    #+#             */
/*   Updated: 2019/12/26 20:31:08 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			is_space(char c)
{
	return (c == ' ' || c == '\t');
}

/*
** Skip space and tab in content
*/

size_t		skip_space(char *content, size_t place)
{
	size_t i;

	i = 0;
	if (content[place] == '\0')
		return (0);
	while (content[i + place] != '\0' && is_space(content[i + place]))
		i++;
	return (i);
}

size_t		skip_spaces(t_cnt **cnt, size_t i)
{
	while ((*cnt) != NULL && (*cnt)->line &&
		((*cnt)->line[(i += skip_space((*cnt)->line, i))] == '\0' ||
		(*cnt)->line[i] == COMMENT_CHAR || (*cnt)->line[i] == ';') &&
		((i = 0) || 1))
		(*cnt) = (*cnt)->next;
	return (i);
}
