/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <arcohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 13:19:46 by arcohen           #+#    #+#             */
/*   Updated: 2018/12/14 22:20:08 by arcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int check_if_dup(t_line *pipe, char *name)
{
    char *link;

    // if (pipe == NULL)
    //     return (0);
    while (pipe->next)
    {
        // ft_putstr(name);
        // ft_putchar(10);
        if (ft_strequ(pipe->line, name))
            return (1);
        link = &pipe->line[find_char(pipe->line, '-') + 1];
        if (ft_strnequ(link, name, ft_strlen(link)))
        {
            link = &name[find_char(name, '-') + 1];
            if (ft_strnequ(link, pipe->line, ft_strlen(link)))
                return (1);
        }
        pipe = pipe->next;
    }
    return (0);
}

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

t_line *find_name(int id, t_line *rooms)
{
    while (rooms->next)
    {
        if (rooms->id == id)
            return (rooms);
        rooms = rooms->next;
    }
    return (0);
}

void path_nodes(t_path *path, t_line *pipes, t_line *rooms)
{
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
    map->room_start->id = find_id(map->room_start->line, map->rooms);
    map->room_end->id = find_id(map->room_end->line, map->rooms);
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




int search_nodes(t_path *path, int id, t_line *rooms)
{
    while (path->next)
    {
        ft_putstr("\nnode:\n");
        ft_putstr(find_name(path->link1, rooms)->line);
        ft_putchar('-');
        ft_putstr(find_name(path->link2, rooms)->line);
        ft_putchar('-');
        ft_putnbr(path->open);
        if (path->open)
        {
            if (id == path->link1 && find_name(path->link2, rooms)->open)
            {
                ft_putstr("\nFOUND\n");
                path->open = 0;
                find_name(id, rooms)->open = 0;
                return (path->link2);
            }
            else if (id == path->link2 && find_name(path->link1, rooms)->open)
            {
                ft_putstr("\nFOUND:\n");
                path->open = 0;
                find_name(id, rooms)->open = 0;
                return (path->link1);
            }
        }
        path = path->next;
    }
    return (0);
}

// t_crumbs    *create_crumb(t_crumbs *curr, t_path *previous)
// {
//     curr = (t_line *)malloc(sizeof(t_line));
// }

int path_finder(t_map *map, t_path *path)
{
    //int prev_id;
    int id;
    int tmp;

    id = map->room_start->id;
    ft_putstr(map->room_start->line);
    ft_putstr(" - ");
    ft_putnbr(id);
    ft_putchar(10);
    // prev_id = id;
    map->id_arr_size = 0;
    while (1)
    {
        ft_putstr("\nCurrent node location:\n");
        ft_putstr(find_name(id, map->rooms)->line);
        ft_putchar(10);
        if ((tmp = search_nodes(path, id, map->rooms)))
        {
            ft_putstr("\nArray size:\n");
            ft_putnbr(map->id_arr_size);
            ft_putchar(10);
            map->id_paths[map->id_arr_size++] = id;
            //prev_id = id;
            id = tmp;
        }
        else if (id == map->room_end->id)
            return (1);
        else
        {
            ft_putstr("\nBACK ONE PATH\n");
            if (--map->id_arr_size < 0)
                return (0);
            id = map->id_paths[map->id_arr_size];
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
    ft_putstr("\nPath Array:\n");
    while (i < map->id_arr_size)
    {
        ft_putchar('|');
        ft_putstr(find_name(map->id_paths[i++], map->rooms)->line);
        ft_putchar('|');
    }
    ft_putchar(10);
    return (1);
}
