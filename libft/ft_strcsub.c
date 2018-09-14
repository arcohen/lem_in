/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcohen <arcohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 15:44:20 by arcohen           #+#    #+#             */
/*   Updated: 2018/09/13 15:52:07 by arcohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcsub(char const *s, unsigned int end)
{
	char	*ret;
	size_t	i;

	i = 0;
	while (s[i++] != end)
		;
	ret = ft_strnew(i);
	if (!s || !ret)
		return (0);
	i = -1;
	while (s[++i] != end)
		ret[i] = s[i];
	return (ret);
}