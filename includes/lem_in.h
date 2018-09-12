/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <arcohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 12:59:37 by arcohen           #+#    #+#             */
/*   Updated: 2018/09/12 13:17:45 by arcohen          ###   ########.fr       */
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

#endif
