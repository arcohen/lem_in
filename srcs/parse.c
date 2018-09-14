/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <arcohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 13:19:12 by arcohen           #+#    #+#             */
/*   Updated: 2018/09/13 18:27:27 by arcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		get_ants(t_map *map, t_line *info)
{
	int i;

	i = 0;
	while (info)
	{
		if (info->line[0] == '#')
			info = info->next;
		else
		{
			while (info->line[i])
			{
				if (ft_isdigit(info->line[i]) == 0)
					return (0);
				i++;
			}
			map->ant_num = ft_atoi(info->line);
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

int		get_rooms(t_map *map, t_line *info)
{
	t_line	*prev;

	map->rooms = (t_line *)malloc(sizeof(t_line));
	prev = info;
	while (info)
	{
		if (is_room(info->line))
		{
			map->rooms->line = info->line;
		}
		prev = info;
		info = info->next;
	}
}

void	getinfo(t_line *info)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		info->line = line;
		info->next = (t_line *)malloc(sizeof(t_line));
		info = info->next;
		info->next = NULL;
	}
}

int		parse(t_map *map, t_line *info)
{
	getinfo(info);
	if (get_ants(map, info) == 0)
	{
		ft_putstr("ERROR IN ANT NUMBER\n");
		return (0);
	}
	if (get_rooms(map, info) == 0)
	{
		ft_putstr("ERROR IN ROOMS\n");
		return (0);
	}
	return (1);
}
