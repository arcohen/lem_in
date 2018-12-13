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

int find_id(char *name, t_line *rooms)
{
    while (rooms->next)
    {
        if (ft_strequ(name, rooms->line))
        return (rooms->id);
        rooms = rooms->next;
    }
    return (0);
}

void path_nodes(t_path *path, t_line *pipes, t_line *rooms) {
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

void save_names(t_map *map, t_line *info)
{
    while (info->next)
    {
        if (ft_strequ(info->line, "##start"))
            map->room_start = info->next;
        else if (ft_strequ(info->line, "##end"))
        {
            map->room_end = info->next;
            break;
        }
        info = info->next;
    }
}

void assign_ids(t_line *rooms) {
    int id;

    id = 1;
    while (rooms->next)
    {
        rooms->id = id;
        id++;
        rooms = rooms->next;
    }
}


int search_nodes(t_path *path, int id)
{
    while (path->next)
    {
        if (path->open)
        {
            if (id == path->link1)
            {
                path->open = 0;
                return (path->link2);
            }
            else if (id == path->link2)
            {
                path->open = 0;
                return (path->link1);
            }
        }
        path = path->next;
    }
    return (0);
}

int path_finder(t_map *map, t_path *path)
{
    int prev_id;
    int id;
    int tmp;

    id = map->room_start->id;
    ft_putnbr(id);
    prev_id = id;
    map->id_arr_size = 0;
    while (1)
    {
        ft_putstr("JustWhilin'\n");
        if ((tmp = search_nodes(path, id)))
        {
            map->id_paths[map->id_arr_size++] = tmp;
            prev_id = id;
            id = tmp;
        }
        else if (id == map->room_end->id)
            return (1);
        else
        {
            if (--map->id_arr_size < 0)
                return (0);
            id = prev_id;
        }
    }
}

void printit(t_path *path) {
    while (path->next)
    {
        ft_putnbr(path->link1);
        ft_putchar('|');
        ft_putnbr(path->link2);
        ft_putchar('|');
        path = path->next;
    }
}

int find_path(t_map *map, t_line *info)
{
    assign_ids(map->rooms);
    save_names(map, info);
    path_nodes(map->path, map->pipes, map->rooms);
    //printit(map->path);
    if (path_finder(map, map->path) == 0)
        return (0);
    int i = 0;
    ft_putstr("shouldbenow:\n");
    while (i < map->id_arr_size)
    {
        ft_putchar('|');
        ft_putnbr(map->id_paths[i++]);
        ft_putchar('|');
    }
    return (1);
}
