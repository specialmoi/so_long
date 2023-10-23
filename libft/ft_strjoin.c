/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthiruma <pthiruma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:34:42 by pthiruma          #+#    #+#             */
/*   Updated: 2023/10/11 19:51:23 by pthiruma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	char	*ptr;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (0);
	i = -1;
	while (s1[++i] != '\0')
		ptr[i] = s1[i];
	i = 0;
	while (s2[i] != '\0')
	{
		ptr[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	ptr[ft_strlen(s1) + i] = '\0';
	free(s1);
	return (ptr);
}