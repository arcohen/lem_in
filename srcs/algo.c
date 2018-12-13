/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <arcohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 13:19:46 by arcohen           #+#    #+#             */
/*   Updated: 2018/09/20 14:53:48 by arcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void path_nodes(t_path *path, t_line *pipes) {
    int i;

    while (pipes->next)
    {
        path->next = (t_path *)malloc(sizeof(t_path));
        path->next->next = NULL;
        i = find_char(pipes->line, '-');
        path->link1 = ft_strsub(pipes->line, 0, i);
        path->link2 = ft_strdup(&pipes->line[i + 1]);
        path->open = 1;
        pipes = pipes->next;
        path = path->next;
    }
}

void save_names(t_map *map, t_line *info)
{
    while (info->next)
    {
        if (ft_strequ(info->line, "##start"))
            ft_strcpy(map->room_start, info->next->line);
        else if (ft_strequ(info->line, "##end"))
        {
            ft_strcpy(map->room_end, info->next->line);
            break;
        }
        info = info->next;
    }
}

void assign_ids(t_line *rooms) {
    int id;

    id = 0;
    while (rooms->next)
    {
        rooms->id = id;
        id++;
        rooms = rooms->next;
    }
}

int find_path(t_map *map, t_line *info)
{
    // t_path *path;
    //
    // path = map->path;
    assign_ids(map->rooms);
    save_names(map, info);
    path_nodes(map->path, map->pipes);
    // ft_putstr("The Names:\n");
    // ft_putstr(map->room_start);
    // ft_putchar('\n');
    // ft_putstr(map->room_end);
    // ft_putchar('\n');
    // ft_putstr("End of The Names\n");
    // ft_putstr("The Paths:\n");
    // while (path->next)
    // {
    //     ft_putstr(path->link1);
    //     ft_putchar('\n');
    //     ft_putstr(path->link2);
    //     ft_putchar('\n');
    //     ft_putchar('\n');
    //     path = path->next;
    // }
    // ft_putstr("End of The Paths\n");
    return (1);
}
