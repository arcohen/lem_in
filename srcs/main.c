/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <arcohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 14:19:04 by arcohen           #+#    #+#             */
/*   Updated: 2018/09/12 16:36:12 by arcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		main(void)
{
	t_map	*map;
	t_line	*info;

	info = (t_line *)malloc(sizeof(t_line));
	map = (t_map *)malloc(sizeof(t_map));
	if (parse(map, info))
		;
	free (map);
	return (0);
}