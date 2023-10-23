/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthiruma <pthiruma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 19:15:26 by pthiruma          #+#    #+#             */
/*   Updated: 2023/02/09 13:51:37 by pthiruma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ptr(unsigned long i, int *len)
{
	int		j;
	char	str[50];
	char	*hex;

	if (!i)
	{
		ft_putstr("(nil)", len);
		return ;
	}
	ft_putstr("0x", len);
	hex = "0123456789abcdef";
	j = 0;
	while (i)
	{
		str[j++] = hex[i % 16];
		i = i / 16;
	}
	while (j--)
		ft_putchar(str[j], len);
}
