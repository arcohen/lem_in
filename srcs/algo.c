/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <marvin@42.fr>           			+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 12:21:39 by arcohen           #+#    #+#             */
/*   Updated: 2018/12/17 21:30:37 by arcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	assign_ids(t_line *rooms)
{
	int id;

	id = 1;
	while (rooms->next)
	{
		rooms->id = id;
		id++;
		rooms = rooms->next;
	}
}

int		search_nodes(t_path *path, int id, t_line *rooms)
{
	while (path->next)
	{
		if (path->open)
		{
			if (id == path->link1 && find_name(path->link2, rooms)->open)
			{
				path->open = 0;
				find_name(id, rooms)->open = 0;
				return (path->link2);
			}
			else if (id == path->link2 && find_name(path->link1, rooms)->open)
			{
				path->open = 0;
				find_name(id, rooms)->open = 0;
				return (path->link1);
			}
		}
		path = path->next;
	}
	return (0);
}

int		path_finder(t_map *map, t_path *path)
{
	int id;
	int tmp;

	id = map->room_start->id;
	map->id_arr_size = 0;
	while (1)
	{
		if (id == map->room_end->id)
		{
			map->id_paths[map->id_arr_size++] = id;
			return (1);
		}
		else if ((tmp = search_nodes(path, id, map->rooms)))
		{
			map->id_paths[map->id_arr_size++] = id;
			id = tmp;
		}
		else
		{
			if (--map->id_arr_size < 0)
				return (0);
			id = map->id_paths[map->id_arr_size];
		}
	}
}

int		find_path(t_map *map, t_line *info)
{
	assign_ids(map->rooms);
	save_names(map, info);
	path_nodes(map->path, map->pipes, map->rooms);
	if (path_finder(map, map->path) == 0)
		return (0);
	return (1);
}
