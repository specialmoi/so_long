/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthiruma <pthiruma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 19:42:39 by pthiruma          #+#    #+#             */
/*   Updated: 2022/12/25 16:26:11 by pthiruma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*sr;

	sr = (unsigned char *)s;
	i = 0;
	while (i < n && sr[i] != (unsigned char)c)
		i++;
	if (i < n && sr[i] == (unsigned char)c)
		return (&sr[i]);
	return (NULL);
}
