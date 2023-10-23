/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthiruma <pthiruma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:30:45 by pthiruma          #+#    #+#             */
/*   Updated: 2023/01/10 14:23:33 by pthiruma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned char	*ptr;
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	k = ft_strlen(s);
	i = 0;
	j = 0;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > (ft_strlen(s) - start))
		ptr = (unsigned char *)malloc(((k - start + 1)) * sizeof(char));
	else
		(ptr = (unsigned char *)malloc((len + 1) * sizeof(char)));
	if (!ptr)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
			ptr[j++] = s[i];
		i++;
	}
	ptr[j] = '\0';
	return ((char *) ptr);
}
