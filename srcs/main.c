/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <arcohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 14:19:04 by arcohen           #+#    #+#             */
/*   Updated: 2018/09/20 14:55:01 by arcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		getinfo(t_line *info)
{
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(0, &line) > 0)
	{
		info->line = line;
		info->next = (t_line *)malloc(sizeof(t_line));
		info = info->next;
		info->next = NULL;
		i++;
	}
	return (i);
}

int		get_pipes(t_map *map, t_line *pipe, t_line *info)
{
	while (ft_strequ(info->cmt, "PIPE_START") == 0)
		info = info->next;
	while (info->next)
	{
		if (info->line[0] == '#')
			;
		else if (is_valid_pipe(map->rooms, info->line))
			pipe = create_link(pipe, info->line, 0);
		else
			return (0);
		info = info->next;
	}
	return (1);
}

int		main(void)
{
	t_map	*map;
	t_line	*info;

	info = (t_line *)malloc(sizeof(t_line));
	map = (t_map *)malloc(sizeof(t_map));
	if (parse(map, info))
	{
		ft_putstr("\n1-");
		ft_putstr(map->rooms->next->line);
		ft_putchar(10);
	}
	return (0);
}
