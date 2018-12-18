/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <marvin@42.fr>      			    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 14:19:04 by arcohen           #+#    #+#             */
/*   Updated: 2018/12/18 16:29:56 by arcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		dup_room(t_line *rooms, char *name)
{
	int k;

	k = 0;
	while (rooms)
	{
		if (ft_strequ(rooms->line, name))
			k++;
		if (k > 1)
			return (1);
		rooms = rooms->next;
	}
	return (0);
}

void	create_errey(char *errey, char *line)
{
	ft_strcat(errey, line);
	ft_strcat(errey, "\n");
}

int		getinfo(t_line *info, char *copy)
{
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(0, &line) > 0)
	{
		create_errey(copy, line);
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
	t_line	*pipe_start;
	int		i;

	i = 0;
	pipe_start = pipe;
	while (ft_strequ(info->cmt, "PIPE_START") == 0)
		info = info->next;
	while (info->next)
	{
		if (info->line[0] == '#')
			;
		else if (strrchr(info->line, ' '))
			return (0);
		else if (is_valid_pipe(map->rooms, info->line))
		{
			if (i == 0 || check_if_dup(pipe_start, info->line) == 0)
				pipe = create_link(pipe, info->line, 0);
			i++;
		}
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
	map->rooms = (t_line *)malloc(sizeof(t_line));
	map->pipes = (t_line *)malloc(sizeof(t_line));
	map->path = (t_path *)malloc(sizeof(t_path));
	if (parse(map, info))
	{
		ft_putstr(map->errey);
		print_ants(map);
	}
	return (0);
}
