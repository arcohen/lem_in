/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <arcohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 13:19:46 by arcohen           #+#    #+#             */
/*   Updated: 2018/09/20 14:53:48 by arcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	check_for_comm(char *cmt, char *prev)
{
	if (!ft_strcmp(prev, "##start"))
		ft_strcpy(cmt, "ROOM_START");
	else if (!ft_strcmp(prev, "##end"))
		ft_strcpy(cmt, "ROOM_END");
}

void	print_rooms(t_line *info)
{
	while (info->next)
	{
		ft_putstr(info->line);
		ft_putchar(10);
		info = info->next;
	}
}

int		find_char(char *str, int c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (0);
}

int		is_valid_pipe(t_line *room, char *pipe)
{
	size_t	d;
	int		first;
	t_line	*head;

	head = room;
	if ((d = find_char(pipe, '-')) == 0 ||
	(ft_strnequ(pipe, &pipe[d + 1], d) && ft_strlen(&pipe[d + 1]) == d))
		return (0);
	while (room->next)
	{
		if (first)
		{
			if (ft_strequ(room->line, &pipe[d + 1]))
				return (1);
		}
		else if (ft_strnequ(room->line, pipe, d) && ft_strlen(room->line) == d)
		{
			first = 1;
			room = head;
		}
		room = room->next;
	}
	return (0);
}

t_line	*create_link(t_line *curr, char *line, int room)
{
	curr->next = (t_line *)malloc(sizeof(t_line));
	curr->next->next = NULL;
	curr->line = line;
	if (room)
		curr->line[find_char(curr->line, ' ')] = 0;
	return (curr->next);
}
