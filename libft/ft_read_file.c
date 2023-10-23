/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthiruma <pthiruma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 23:35:39 by dlu               #+#    #+#             */
/*   Updated: 2023/10/18 13:06:45 by pthiruma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int ft_file_len(const char *filename)
{
	int	fd;
	int	len;
	int size_read;
	char buff[BUFFER_SIZE];
	
	fd = open(filename, O_RDONLY);
	len = 0;
	size_read = 0;
	if (fd == -1)
		return (0);
	while (1)
	{
		size_read = read(fd, buff, BUFFER_SIZE);
		if (size_read <= 0)
			break ;
		len += size_read;
	}
	close (fd);
	return (len);
}

char *ft_read_file(const char *filename)
{
	int fd;
	int	i;
	char *ret;
	char buff[1];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * ft_file_len(filename) + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while(read(fd, buff, 1))
		ret[i++] = *buff;
	ret[i] = '\0';
	close (fd);
	return (ret);
}
