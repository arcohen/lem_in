/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <marvin@42.fr>            			+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 20:50:42 by arcohen           #+#    #+#             */
/*   Updated: 2018/12/17 20:55:16 by arcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		check_if_dup(t_line *pipe, char *name)
{
	char *link;

	while (pipe->next)
	{
		link = &pipe->line[find_char(pipe->line, '-') + 1];
		if (ft_strnequ(link, name, ft_strlen(link)))
		{
			link = &name[find_char(name, '-') + 1];
			if (ft_strnequ(link, pipe->line, ft_strlen(link)))
				return (1);
		}
		pipe = pipe->next;
	}
	return (0);
}

int		find_id(char *name, t_line *rooms)
{
	while (rooms->next)
	{
		if (ft_strequ(name, rooms->line))
			return (rooms->id);
		rooms = rooms->next;
	}
	return (0);
}

t_line	*find_name(int id, t_line *rooms)
{
	while (rooms->next)
	{
		if (rooms->id == id)
			return (rooms);
		rooms = rooms->next;
	}
	return (0);
}

void	path_nodes(t_path *path, t_line *pipes, t_line *rooms)
{
	int i;

	while (pipes->next)
	{
		path->next = (t_path *)malloc(sizeof(t_path));
		path->next->next = NULL;
		i = find_char(pipes->line, '-');
		path->link1 = find_id(ft_strsub(pipes->line, 0, i), rooms);
		path->link2 = find_id(&pipes->line[i + 1], rooms);
		path->open = 1;
		pipes = pipes->next;
		path = path->next;
	}
}

void	save_names(t_map *map, t_line *info)
{
	while (info->next)
	{
		if (ft_strequ(info->line, "##start"))
			map->room_start = info->next;
		else if (ft_strequ(info->line, "##end"))
		{
			map->room_end = info->next;
			break ;
		}
		info = info->next;
	}
	map->room_start->id = find_id(map->room_start->line, map->rooms);
	map->room_end->id = find_id(map->room_end->line, map->rooms);
}
