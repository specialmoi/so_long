/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthiruma <pthiruma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:08:20 by pthiruma          #+#    #+#             */
/*   Updated: 2023/01/09 18:40:11 by pthiruma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*ptr;

	i = 0;
	len = ft_strlen(s) + 1;
	ptr = (char *)malloc(sizeof(char) * len);
	if (!ptr)
		return (NULL);
	while (s[i])
	{
		ptr[i] = *((unsigned char *)(s + i));
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
