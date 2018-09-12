/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <arcohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 13:19:12 by arcohen           #+#    #+#             */
/*   Updated: 2018/09/12 16:45:06 by arcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		get_ants(t_map *map)
{
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(0, &line))
	{
		if (line[0] == '#' && line[1] != '#')
			continue ;
		else 
		{
			while (line[i])
			{
				if (ft_isdigit(line[i]) == 0)
				{
					free(line);
					return (0);
				}
				i++;
			}	
			map->ant_num = ft_atoi(line);
			free(line);
			return (1);
		}
	}
	return (0);
}

int		get_rooms(t_map *map)
{
	char *line;

	//map->rooms
	while (get_next_line(0, &line))
	{
		if (line[0] == '#' && line[1] != '#')
			continue ;
		
	}
}

void	getinfo(t_line *info)
{
	char	*line;
	t_line	*temp;

	while (get_next_line(0, &line) > 0)
	{
		info->line = line;
		temp = (t_line *)malloc(sizeof(t_line));
		info->next = temp;
		info = temp;
		info->next = NULL;
	}
}

int		parse(t_map *map, t_line *info)
{
	getinfo(info);
	if (get_ants(map) == 0)
	{
		ft_putstr("ERROR IN ANT NUMBER\n");
		return (0);		
	}
	if (get_rooms(map) == 0)
	{
		ft_putstr("ERROR IN ROOMS\n");
		return (0);
	}
	return (1);
}

