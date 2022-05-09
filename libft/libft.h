/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rricol <rricol@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:02:37 by rricol            #+#    #+#             */
/*   Updated: 2022/03/15 21:02:37 by rricol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/* includes */
// standard libraries
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/* defines */
# define ERR -1
# define TRUE 1
# define FALSE 0
# define ERR_MSG "Error\n"
# define ERR_ARG "invalid number of arguments.\n"
# define STDIN	0
# define STDOUT	1
# define STDERR	2

/* prototypes */
// output
int			ft_putchar(char c);
int			ft_putchar_fd(char c, int fd);
int			ft_putstr(char *s);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putendl(char *s);
int			ft_printf(char *input, ...);
int			ft_putnbr(long n);
int			ft_putnbr_fd(long n, int fd);
int 		ft_putnbr_base(unsigned int n, char *base);

// count
int			ft_strlen(char * s);
int			ft_count_char(char *s, char c);
int			ft_count_words(char *s, char c);
int			ft_count_lines(char *s);

// control
int			ft_isspace(char c);
int			ft_isalnum(int c);
int			ft_isalpha(char c);
int			ft_isdigit(char c);
int			ft_isascii(int c);
int			ft_isprint(int c);

// string manipulation
size_t		ft_strlcat(char *dst, char *src, size_t dstsize);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		**ft_split(char *s, char c);
int			ft_strncmp(char *s1, char *s2, size_t n);
int			ft_atoi(char *s);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strrchr(char *s, int c);
char		*ft_strchr(char *s, int c);
char		*ft_strdup(char *s);
char		*ft_strndup(char *s, int n);

// number manipulation
char		*ft_itoa(int n);

// memory manipulation
void		ft_bzero(void *s, size_t len);
void		*ft_memset(void *b, int c, size_t len);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);

// other
char		*ft_gnl(int fd, char *s);

#endif
