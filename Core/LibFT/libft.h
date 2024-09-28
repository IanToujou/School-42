/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < libft.h >                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:28:41 by ibour             #+#    #+#             */
/*   Updated: 2024/08/05 16:28:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <malloc.h>
# include <stdbool.h>
# include <unistd.h>

#ifndef ULONG_MAX
# define ULONG_MAX 0xFFFFFFFFUL
#endif

#ifndef M_PI
# define M_PI 3.14159265358979323846
#endif

typedef unsigned char	t_byte;

int					ft_atoi(const char *str);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_isprint(int c);
int					ft_isalnum(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_itoa(int n);

char				*ft_strdup(const char *src);
unsigned int		ft_strlcpy(char *dest, char *src, unsigned int size);
unsigned int		ft_strlcat(char *dst, char *src, unsigned int n);
size_t				ft_strlen(const char *s);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *s, const char *to_find, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

__attribute__((unused)) void				*ft_calloc(size_t count, size_t size);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, void *src, size_t s);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_bzero(void *s, size_t n);

void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

void				*ft_memccpy(void *dest, void *src, int c, size_t n);
void				ft_memdel(void **ap);

char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, unsigned int n);
char				*ft_strcat(char *dst, char *src);
char				*ft_strncat(char *dst, const char *src, unsigned int n);
char				*ft_strstr(char *s, char *to_find);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
char				*ft_strmap(char const *s, char (*f)(char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);

void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);

double				ft_pow(double x, int y);
double				ft_min(double x, double y);
double				ft_max(double x, double y);
double				ft_floor(double x);
double				ft_ceil(double x);
int					ft_factorial(int x);
double				ft_cos(double x);
double				ft_sin(double x);
double				ft_tan(int x);
double				ft_round(int x);
double				ft_reduce_angle(double x);

void				ft_overflow(void);

int					ft_isblank(int c);
int					ft_isspace(int c);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **list, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

typedef struct s_hashnode
{
	char				*key;
	int 				value;
	struct s_hashnode	*next;
}	t_hashnode;

typedef struct s_hashtable
{
	int			size;
	t_hashnode	**table;
}	t_hashtable;

unsigned int		ft_hashcode(const char *key, int size);
t_hashtable			*ft_hashnew(int size);
void				ft_hashinsert(t_hashtable *table,
						const char *key, int value);
int					ft_hashsearch(t_hashtable *table, const char *key);
void				ft_hashdel(t_hashtable *table, const char *key);
void				ft_hashclear(t_hashtable *table);

#endif
