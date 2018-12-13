/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <arcohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 13:19:12 by arcohen           #+#    #+#             */
/*   Updated: 2018/09/26 15:26:22 by arcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		check_rooms(t_line *rooms)
{
	int start;
	int end;

	start = 0;
	end = 0;
	while (rooms)
	{
		if (ft_strequ(rooms->cmt, "ROOM_START"))
			start++;
		else if (ft_strequ(rooms->cmt, "ROOM_END"))
			end++;
		rooms = rooms->next;
	}
	if (start == 1 && end == 1)
		return (1);
	return (0);
}

int		get_ants(t_map *map, t_line *info)
{
	int i;

	i = 0;
	while (info->next)
	{
		if (info->line[0] == '#')
			info = info->next;
		else
		{
			while (info->line[i])
			{
				if (ft_isdigit(info->line[i]) == 0 || ft_atoi(info->line) == 0)
					return (0);
				i++;
			}
			map->ant_num = ft_atoi(info->line);
			if (info->next)
				ft_strcpy(info->next->cmt, "ROOM_BEGIN");
			else
				ft_strcpy(info->cmt, "ROOM_BEGIN");
			return (1);
		}
	}
	return (0);
}

int		is_room(char *line)
{
	int count;

	if (line[0] == '#' || line[0] == 'L')
		return (0);
	count = 0;
	while (*line)
	{
		if (*line == ' ')
			count++;
		else if (count)
			if (!ft_isdigit(*line))
				return (0);
		line++;
	}
	if (count == 2)
		return (1);
	return (0);
}

int		get_rooms(t_line *rooms, t_line *info)
{
	t_line	*prev;

	prev = info;
	while (ft_strequ(info->cmt, "ROOM_BEGIN") == 0)
		info = info->next;
	while (info->next)
	{
		if (is_room(info->line))
		{
			rooms = create_link(rooms, info->line, 1);
			check_for_comm(rooms->cmt, prev->line);
		}
		else if (info->line[0] == '#')
			;
		else
		{
			ft_strcpy(info->cmt, "PIPE_START");
			return (1);
		}
		prev = info;
		info = info->next;
	}
	return (0);
}

int		parse(t_map *map, t_line *info)
{
	if (getinfo(info) == 0)
		ft_putstr("EMPTY MAP\n");
	else if (get_ants(map, info) == 0)
		ft_putstr("ERROR IN ANT NUMBER\n");
	else if (get_rooms(map->rooms, info) == 0 || check_rooms(map->rooms) == 0)
		ft_putstr("ERROR IN ROOMS\n");
	else if (get_pipes(map, map->pipes, info) == 0)
	{
		print_rooms(map->rooms);
		ft_putstr("ERROR IN PIPES\n");
	}
	else if (find_path(map, info) == 0)
		ft_putstr("NO POSSIBLE SOLUTION\n");
	else
	{
		print_rooms(map->rooms);
		ft_putstr("\n\n\n\n");
		ft_putchar(10);
		print_rooms(info);
		return (1);
	}
	return (0);
}
