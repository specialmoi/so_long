/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthiruma <pthiruma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:50:59 by pthiruma          #+#    #+#             */
/*   Updated: 2023/01/09 18:48:54 by pthiruma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ptr;

	i = 0;
	ptr = ft_strdup(s);
	if (!ptr)
		return (NULL);
	while (ptr[i] != '\0')
	{
		ptr[i] = (*f)(i, ptr[i]);
		i++;
	}
	return (ptr);
}
