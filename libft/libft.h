/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthiruma <pthiruma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 08:37:45 by pthiruma          #+#    #+#             */
/*   Updated: 2023/10/17 14:32:35 by pthiruma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
#include <fcntl.h>


int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int x);
int		ft_isascii(int i);
int		ft_isprint(int i);
int		ft_toupper(int c);
int		ft_tolower(int c);

size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);

char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strtrim(char const *s1, char const *set);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);

int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);
void	ft_bzero(void *s, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

//printf
void	ft_format(va_list args, char s, int *len);
int	ft_printf(const char *s, ...);
void	ft_hex(unsigned int i, int *len, char y);
void	ft_ptr(unsigned long i, int *len);
void	ft_putchar(char c, int *len);
void	ft_putdec(int i, int *len);
void	ft_putdec_u(unsigned int i, int *len);
void	ft_putstr(char *s, int *len);

//gnl
char	*get_next_line(int fd);
char	*ft_new_line(char *static_buffer);
char	*ft_line(char *static_buffer);
char	*read_text(int fd, char *static_buffer);

// so_long
char	*ft_read_file(const char *filename);
int		ft_collen(char **arr);

#endif
