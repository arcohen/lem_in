/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <marvin@42.fr>            			+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 12:21:11 by arcohen           #+#    #+#             */
/*   Updated: 2018/12/15 13:02:52 by arcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	print_ants(t_map *map)
{
	int i;
	int j;

	ft_putchar(10);
	i = 1;
	while (i <= map->ant_num)
	{
		j = 1;
		while (j < map->id_arr_size)
		{
			ft_putchar('L');
			ft_putnbr(i);
			ft_putchar('-');
			ft_putstr(find_name(map->id_paths[j], map->rooms)->line);
			ft_putchar(10);
			j++;
		}
		i++;
	}
}
