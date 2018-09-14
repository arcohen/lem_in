/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <arcohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 12:59:37 by arcohen           #+#    #+#             */
/*   Updated: 2018/09/13 17:23:19 by arcohen          ###   ########.fr       */
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
}				t_map;

typedef struct	s_line
{
	struct s_line	*next;
	char			*line;
	char			cmt[20];

}				t_line;

int		parse(t_map *map, t_line *info);
int		is_room(char *line);

#endif
