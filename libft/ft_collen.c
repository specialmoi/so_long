/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthiruma <pthiruma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:08:56 by dlu               #+#    #+#             */
/*   Updated: 2023/10/15 16:05:42 by pthiruma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_collen(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i])
		i++;
	return (i);
}

