/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:23:12 by mpoesy            #+#    #+#             */
/*   Updated: 2024/12/06 11:16:08 by mpoesy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../../../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* '-' = 000001
 * '0' = 000010
 * '.' = 000100
 * '#' = 001000
 * '+' = 010000
 * ' ' = 100000
 */

# define FLAG_MINUS 0b000001
# define FLAG_ZERO 0b000010
# define FLAG_DOT 0b000100
# define FLAG_HASH 0b001000
# define FLAG_PLUS 0b010000
# define FLAG_SPACE 0b100000

typedef struct s_format
{
	int		flags;
	int		iswidthsetup;
	int		width;
	size_t	precision;
}			t_format;

typedef struct s_padding
{
	int		padding_len;
	int		total_len;
	int		index;
	char	pad_char;
}			t_padding;

int			ft_printf(const char *str, ...);
int			print_c(int c, t_format *format);
int			print_s(char *str, t_format *format);
int			print_p(void *ptr, t_format *format);
int			print_d(int nbr, t_format *format);
int			print_i(int nbr, t_format *format);
int			print_u(unsigned int nbr, t_format *format);
int			print_x(unsigned int nbr, t_format *format);
int			print_cx(unsigned int nbr, t_format *format);
int			print_prc(void);
int			parse_width(const char **str, int *iswidthsetup);
size_t		parse_precision(const char **str, int *flag);
t_format	parse_format(const char **str);
int			parse_flags(const char **str);
char		*apply_flags(char *str, t_format *format, char specifier);
char		*add_prefix(char *str, char specifier);
char		*ft_itoa_base(size_t num, int base);
char		*ft_utoa(unsigned int n);
char		*apply_width_and_padding(char *str, t_format *format,
				char specifier);
int			handle_zero(t_format *format);
char		*apply_hash_flag(char *str, t_format *format, char specifier);
char		*precision_d(char *str, t_format *format);
char		*precision_s(char *str, t_format *format);
char		*precision_u(char *str, t_format *format);
char		*precision_x(char *str, t_format *format);
char		*precision_cx(char *str, t_format *format);

int			calculate_length(char *str, char specifier);
void		compute_lengths(int len_str, int width, t_padding *pad);
char		*allocate_result(char *str, int width, int total_len,
				int is_width_set);
void		add_padding(char *final_str, t_padding *pad);
void		copy_string(char *final_str, char *str, t_padding *pad);
int			i_dont_get_why_its_like_this(t_format *format, char specifier);

#endif
