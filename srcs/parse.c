/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <arcohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 13:19:12 by arcohen           #+#    #+#             */
/*   Updated: 2018/09/12 14:06:31 by arcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		get_ants(char **av, t_map *map)
{
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(0, &line))
	{
		if (line[0] == '#' && line[1] != '#')
			continue ;
		while (line[i])
		{
			if (ft_isdigit(line[i]) == 0)
			{
				free(line);
				return (0);
			}
			i++;
			free(line);
		}
		map->ant_num = ft_atoi(line);
	}
	return (1);
}

int		parse(char **av, int ac, t_map *map)
{
	if (get_ants(av, map) == 0)
	{
		ft_putstr("ERROR IN ANT NUMBER\n");
		return (0);		
	}
}

