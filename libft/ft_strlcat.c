/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthiruma <pthiruma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 15:08:12 by pthiruma          #+#    #+#             */
/*   Updated: 2022/12/25 12:02:46 by pthiruma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (size + src_len);
	while (*dst != 0)
	{
		dst++;
		size--;
	}
	while ((size - 1) > 0 && *src != 0)
	{
		*dst = *src;
		dst++;
		src++;
		size--;
	}
	*dst = 0;
	return (dst_len + src_len);
}
