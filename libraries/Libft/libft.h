/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrispol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:21:05 by pcrispol          #+#    #+#             */
/*   Updated: 2022/10/11 17:21:08 by pcrispol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H

# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>
# include<string.h>
# include<stdint.h>
#include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct s_list
{
	void				*content;
	struct s_list		*next;
}					t_list;

/************/
/*  libft  */
/************/
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *s);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_atoi(const char *nptr);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_lstsize(t_list *lst);
char	**ft_split(const char *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strdup(const char *src);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char	*big, const char *little, size_t len);
char	*ft_strtrim(const char *s1, const char *set);
char	*ft_itoa(int n);
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *str, int c, size_t n);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstadd_front(t_list **alst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void*));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *));
t_list	*ft_lstnew(void *content);

/************/
/*  printf  */
/************/
size_t	ft_len(long long n);
int		ft_printf(const char *str, ...);
int	ft_formats(va_list args, const char format);
int	ft_putchar(char c);
int	ft_putnbr(int nb);
int	ft_print_c(int c);
int	ft_print_s(char *str);
int	ft_print_di(int n);
int	ft_ptr_len(unsigned long num);
int	ft_print_p(unsigned long p);
int	ft_num_len(unsigned	int num);
int	ft_print_u(unsigned int n);
int	ft_hex_len(unsigned	int num);
int	ft_print_x(unsigned int num, const char format);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
void	ft_putstr(char *str);
void	do_itoa(unsigned int tmp, char *str, int len);
void	ft_put_ptr(unsigned long num);
void	ft_put_hex(unsigned int num, const char format);

/*******************/
/*  get_next_line  */
/*******************/
size_t	ft_strlen(const char *theString);
char	*ft_strchr(const char *string, int searchedChar );
char	*get_next_line(int fd);
char	*ft_free(char *buffer, char *buf);
char	*ft_next(char *buffer);
char	*ft_line(char *buffer);
char	*read_file(int fd, char *res);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_bzero_gnl(void *s, size_t n);
void	*ft_calloc_gnl(size_t elementCount, size_t elementSize);

#endif
