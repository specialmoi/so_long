/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlong.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthiruma <pthiruma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 08:38:22 by pthiruma          #+#    #+#             */
/*   Updated: 2023/07/08 14:53:04 by pthiruma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Minimum value of long: -9223372036854775808
// Maximum value of long: 9223372036854775807

/* void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}
 */
void	ft_putlong(long l, int *len)
{
	char	c;

	if (l == -9223372036854775807 - 1)
	{
		write(1, "-9223372036854775808", 20);
		(*len) += 20;
		return ;
	}
	if (l < 0)
	{
		ft_putchar('-', len);
		l *= -1;
	}
	if (l > 9)
		ft_putlong(l / 10, len);
	c = l % 10 + 48;
	ft_putchar(c, len);
}
/* 
int main(void)
{
	long num; 
	int len[19];
	// int *int_ptr;

	num = -9223372036854775807L - 1;
	// len = 9;
	// int_ptr = &len;
	ft_putlong(num, len);
} */