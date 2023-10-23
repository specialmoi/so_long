/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdec_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthiruma <pthiruma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:26:08 by pthiruma          #+#    #+#             */
/*   Updated: 2023/02/09 13:55:39 by pthiruma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putdec_u(unsigned int i, int *len)
{
	char	c;

	if (i > 9)
		ft_putdec(i / 10, len);
	c = i % 10 + 48;
	ft_putchar(c, len);
}
