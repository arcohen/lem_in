/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <arcohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 12:59:37 by arcohen           #+#    #+#             */
/*   Updated: 2018/12/15 12:57:40 by arcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"

// typedef struct	s_crumbs
// {
// 	struct s_crumbs	*next_crumb;
// 	struct s_path	*prev;
// 	int		id;
// }		t_crumbs;

typedef struct	s_path
{
	int		link1;
	int		link2;
	int		open;
	// int		prev_id;
	struct s_path	*next;
}		t_path;

typedef struct	s_map
{
	int		ant_num;
	int		r_count;
	struct s_line	*room_start;
	struct s_line	*room_end;
	int		id_paths[1000];
	int		id_arr_size;
	struct s_line	*rooms;
	struct s_line	*pipes;
	struct s_path	*path;
}		t_map;

typedef struct	s_line
{
	struct s_line	*next;
	char		*line;
	char		cmt[20];
	int		id;
	int		open;
}		t_line;

int		parse(t_map *map, t_line *info);
int		is_room(char *line);
int		check_rooms(t_line *room);
int		find_char(char *str, int c);
int		is_valid_pipe(t_line *rooms, char *pipe);
t_line	*create_link(t_line *curr, char *line, int room);
void	print_rooms(t_line *info);
void	check_for_comm(char *cmt, char *prev);
void	print_rooms(t_line *info);
int		get_pipes(t_map *map, t_line *pipe, t_line *info);
int		getinfo(t_line *info);
int		find_char(char *str, int c);
int		find_path(t_map *map, t_line *info);
int 		check_if_dup(t_line *pipe, char *name);
t_line	*find_name(int id, t_line *rooms);
void print_ants(t_map *map);

#endif
