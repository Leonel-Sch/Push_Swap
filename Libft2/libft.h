/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/05/21 16:50:30 by lscheupl          #+#    #+#             */
/*   Updated: 2024/05/21 16:50:30 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

# define UL unsigned long long
# define HEXAL "0123456789abcdef"
# define HEXAU "0123456789ABCDEF"
# define B10 "0123456789"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_pile
{
	int				content;
	struct s_pile	*next;
	struct s_pile	*prev;
}	t_pile;

char		*ft_strcat(char *s1, char *s2);
long long	ft_atoll(const char *nptr);
int			ft_count_words(const char *s, char c);
void		ft_putchar_nb(char c, int *count);
void		ft_putstr_f(char *s, int *count);
void		ft_putnbr_base_f(long long nb, char *base, int *count);
void		ft_putnbr_base_fd(long long nb, char *base, int fd);
int			ft_printf(const char *format, ...);
int			ft_dependance(const char *format, va_list ap, int *count, int i);
void		ft_pointer(unsigned long long nb, int *count);
void		ft_putnbr_base_ul(unsigned long long nb, char *base, int *count);
size_t		ft_strlen(const char *str);
int			ft_atoi(const char *nptr);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
int			ft_isalnum(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
char		*ft_itoa(int n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *s, int c, size_t n);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s);
size_t		ft_strlcat(char *dst, const char *src, size_t siz);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlen(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strchr(const char *s, int c);
int			ft_tolower(int c);
int			ft_toupper(int c);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		**ft_split(char const *s, char c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strcpy(char const *src, char *dest);
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
char		**ft_free_tab(char **tab, int i);
t_pile		*ft_pilenew(int content);
void		ft_pileadd_front(t_pile **pile, t_pile *new);
int			ft_pilesize(t_pile *pile);
t_pile		*ft_pilelast(t_pile *pile);
void		ft_pileadd_back(t_pile **pile, t_pile *new);
void		ft_piledelone(t_pile *pile, void (*del)(int *));
void		ft_pileclear(t_pile **pile, void (*del)(int *));
void		ft_pileiter(t_pile *pile, void (*f)(int));
t_pile		*ft_pilemap(t_pile *pile, int (*f)(int), void (*del)(int *));
t_pile		*ft_pilefirst(t_pile *pile);

#endif
