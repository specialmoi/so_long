/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthiruma <pthiruma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:49:09 by pthiruma          #+#    #+#             */
/*   Updated: 2023/01/09 19:27:56 by pthiruma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		len;
	int		j;

	j = 0;
	len = ft_strlen(s1);
	if (!s1)
		return (ft_strdup(""));
	if (!set)
		return (ft_strdup(s1));
	while (ft_strchr(set, s1[j]) != NULL)
		j++;
	while (ft_strrchr(set, s1[len - 1]) != NULL)
		len--;
	if (len < j)
		return (ft_strdup(""));
	ptr = (char *)malloc(sizeof(*s1) * (len - j + 1));
	if (!ptr)
		return (NULL);
	ft_strlcpy ((char *)ptr, (s1 + j), (len - j + 1));
	return ((char *)ptr);
}
