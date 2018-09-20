/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <arcohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 12:59:37 by arcohen           #+#    #+#             */
/*   Updated: 2018/09/20 14:55:30 by arcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"

typedef struct	s_map
{
	int				ant_num;
	int				r_count;
	struct s_line	*rooms;
	struct s_line	*pipes;
}				t_map;

typedef struct	s_line
{
	struct s_line	*next;
	char			*line;
	char			cmt[20];

}				t_line;

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

#endif
