/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlong_y.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthiruma <pthiruma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 08:59:45 by pthiruma          #+#    #+#             */
/*   Updated: 2023/07/08 14:53:16 by pthiruma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
} */

// Maximum value of unsigned long: 18446744073709551615

void	ft_putlong_y(unsigned long y, int *len)
{
	char	c;

	if (y > 9)
		ft_putlong_y(y / 10, len);
	c = y % 10 + 48;
	ft_putchar(c, len);
}

/* int main(void)
{
	unsigned long num; 
	int len[20];

	num = 18446744073709551615UL;
	ft_putlong_y(num, len);
} */