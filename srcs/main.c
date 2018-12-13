/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <arcohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 14:19:04 by arcohen           #+#    #+#             */
/*   Updated: 2018/09/26 16:20:07 by arcohen          ###   ########.fr       */
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

void	lstdel(t_line **alst, int del)
{
	t_line *next;
	t_line *current;

	current = *alst;
	while (current)
	{
		next = current->next;
		if (del)
			free(current->line);
		free(current);
		current = next;
	}
	*alst = NULL;
}

void	free_all(t_map *map, t_line *info)
{
	if (map->rooms)
		lstdel(&map->rooms, 0);
	if (map->pipes)
		lstdel(&map->pipes, 0);
	lstdel(&info, 1);
	free(info);
	free(map);
}

int		main(void)
{
	t_map	*map;
	t_line	*info;

	info = (t_line *)malloc(sizeof(t_line));
	map = (t_map *)malloc(sizeof(t_map));
	map->rooms = (t_line *)malloc(sizeof(t_line));
	map->pipes = (t_line *)malloc(sizeof(t_line));
	map->path = (t_path *)malloc(sizeof(t_path));
	// map->rooms = NULL;
	// map->pipes = NULL;
	if (parse(map, info))
	{
		ft_putstr("\n1-");
		ft_putstr(map->rooms->next->line);
		ft_putchar(10);
	}
	// t_line *rooms = map->rooms;
	// while (rooms->next)
	// {
	// 	ft_putchar(10);
	// 	ft_putnbr(map->rooms->id);
	// 	ft_putchar(10);
	// 	rooms = rooms->next;
	// }
	//free_all(map, info);
	return (0);
}
