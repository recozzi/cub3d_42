/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:43:26 by recozzi           #+#    #+#             */
/*   Updated: 2023/10/20 19:19:29 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include <string.h>
# include <fcntl.h>

// fd =========================================================================== //

void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int nb, int fd);

// is =========================================================================== //

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_tolower(int c);
int			ft_toupper(int c);
int			ft_isspace(char c);

// mem =========================================================================== //

void		*ft_memset(void *p_s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
void		*ft_free(void **ptr);
void		*ft_custom_realloc(void *ptr, size_t new_size, size_t nmemb_size);
int			ft_memcmp(const void *s1, const void *s2, size_t n);

// str =========================================================================== //

typedef struct s_var
{
	size_t	nb_str;
	size_t	i;
	size_t	j;
	size_t	k;
	char	*trim;
	char	**array_p;
}	t_var;

int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_atoi(const char *nptr);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strlen_offset(char *str, char c);
int			ft_strlen_until(char *str, char *until);
size_t		ft_strlen(const char *str);
size_t		ft_strlcpy(char *dest, const char *src, size_t destsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t		ft_matrixlen(char **argv);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_itoa(int n);
char		**ft_split(char const *s, char c);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
long int	ft_atol(const char *nptr);
double		ft_atof(const char *nptr);

// ft_printf =========================================================================== //

int			ft_print_char(int c);
int			ft_print_str(char *str);
int			ft_print_nbr(int nbr);
int			ft_print_unbr(unsigned int nbr);
int			ft_print_hex(unsigned int nbr, char format);
int			ft_print_pointer(uintptr_t ptr);
int			ft_printf(const char *str, ...);

// ft_printf_fd =========================================================================== //

int			ft_print_char_fd(int c, int fd);
int			ft_print_hex_fd(unsigned int n, char format, int fd);
int			ft_print_nbr_fd(int n, int fd);
int			ft_print_ptr_fd(uintptr_t ptr, int fd);
int			ft_print_str_fd(char *str, int fd);
int			ft_printf_fd(int fd, char *str, ...);
size_t		ft_print_unbr_fd(long int n, int fd);

// get_next_line =========================================================================== //

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char		*get_next_line(int fd);

#endif
