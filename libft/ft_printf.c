/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthiruma <pthiruma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:58:50 by pthiruma          #+#    #+#             */
/*   Updated: 2023/02/09 13:49:00 by pthiruma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_format(va_list args, char s, int *len)
{
	if (s == 'c')
		ft_putchar(va_arg(args, int), len);
	if (s == 's')
		ft_putstr(va_arg(args, char *), len);
	if (s == 'd' || s == 'i')
		ft_putdec(va_arg(args, int), len);
	if (s == 'u')
		ft_putdec_u(va_arg(args, unsigned int), len);
	if (s == 'x')
		ft_hex(va_arg(args, int), len, s);
	if (s == 'X')
		ft_hex(va_arg(args, int), len, s);
	if (s == '%')
		ft_putchar('%', len);
	if (s == 'p')
		ft_ptr(va_arg(args, unsigned long), len);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		len;

	len = 0;
	i = 0;
	if (!s)
		return (0);
	va_start(args, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%' && ft_strchr("cspdiuxX%", s[i + 1]))
		{
			ft_format(args, s[i + 1], &len);
			i++;
		}
		else
			ft_putchar(s[i], &len);
		i++;
	}
	va_end(args);
	return (len);
}
