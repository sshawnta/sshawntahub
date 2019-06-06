/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshawnta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:19:28 by sshawnta          #+#    #+#             */
/*   Updated: 2019/04/09 13:43:15 by sshawnta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

typedef	struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;
int				ft_atoi(const char *str);
void			ft_bzero(void *b, size_t n);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int a);
int				ft_isprint(int c);
void			*ft_memccpy (void *s1, const void *s2, int c, size_t n);
void			*ft_memchr (const void *arr, int c, size_t n);
int				ft_memcmp(const void *buf1, const void *buf2, size_t count);
char			*ft_strrev(char *str);
void			*ft_memcpy(void *s1, const void *s2, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t count);
void			*ft_memset (void *destination, int c, size_t n);
char			*ft_stralloc(const char *s);
char			*ft_strcat(char *string1, const char *string2);
char			*ft_strchr (const char *str, int ch);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strdup(const char *s1);
size_t			ft_strlcat(char *restrict dst, const char *restrict src, \
							size_t size);
size_t			ft_strlen(const char *str);
char			*ft_strncat(char *string1, const char *string2, size_t count);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
char			*ft_strncpy(char *string1, const char *string2, size_t count);
char			*ft_strnstr(const char *haystack, const char *needle, \
							size_t len);
char			*ft_strrchr(const char *str, int ch);
char			*ft_strstr(const char *haystack, const char *needle);
int				ft_tolower(int c);
int				ft_toupper(int c);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			ft_putchar_fd(char c, int fd);
void			ft_putchar(char c);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putendl(char const *s);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbr(int n);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putstr(char const *s);
void			ft_strclr(char *s);
void			ft_strdel(char **as);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char(*f)(unsigned int, char));
char			*ft_strnew(size_t size);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			**ft_strsplit(char const *s, char c);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
char			*ft_itoa(int n);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
#endif
