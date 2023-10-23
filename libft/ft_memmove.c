/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthiruma <pthiruma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:45:12 by pthiruma          #+#    #+#             */
/*   Updated: 2022/12/25 16:01:59 by pthiruma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char			*dest_buffer;
	unsigned const char		*src_buffer;

	dest_buffer = dest;
	src_buffer = src;
	if (!dest && !src)
		return (NULL);
	if (src_buffer < dest_buffer)
	{
		while (n--)
			dest_buffer[n] = src_buffer[n];
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
