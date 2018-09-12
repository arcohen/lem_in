/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <arcohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 12:59:37 by arcohen           #+#    #+#             */
/*   Updated: 2018/09/12 16:45:01 by arcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include "../libft/libft.h"

typedef struct	s_map
{
	int		ant_num;
	char 	**rooms;
	char	*start;
	char	*end;
}				t_map;

typedef struct	s_line
{
	struct s_line	*next;
	char			*line;

}				t_line;

int		parse(t_map *map, t_line *info);

#endif
