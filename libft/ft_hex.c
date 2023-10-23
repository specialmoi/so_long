/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthiruma <pthiruma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:34:49 by pthiruma          #+#    #+#             */
/*   Updated: 2023/02/09 13:50:39 by pthiruma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_hex(unsigned int i, int *len, char y)
{
	int		j;
	char	str[50];
	char	*hex;

	j = 0;
	if (y == 'x')
		hex = "0123456789abcdef";
	if (y == 'X')
		hex = "0123456789ABCDEF";
	if (i == 0)
	{
		ft_putchar('0', len);
	}
	while (i)
	{
		str[j++] = hex[i % 16];
		i = i / 16;
	}
	while (j--)
		ft_putchar(str[j], len);
}
