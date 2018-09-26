/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 22:25:46 by sivasysh          #+#    #+#             */
/*   Updated: 2018/03/12 22:25:47 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# define QUALIFIER(q) Q1(q) || Q2(q) || Q3(q) || Q4(q)
# define Q1(q) q == 'f' || q == 'F' || q == 's' || q == 'S' || q == 'p'
# define Q2(q) q == 'd' || q == 'D' || q == 'i' || q == 'o' || q == 'O'
# define Q3(q) q == 'U' || q == 'x' || q == 'X' || q == 'c' || q == 'C'
# define Q4(q) q == 'Z' || q == 'R' || q == 'u' || q == '%'
# define FLAG(f) F1(f) || F2(f) || F3(f)
# define F1(f) f == ' ' || f == '#' || f == '0' || f == '-' || f == '+'
# define F2(f) f == '.' || f == '\'' || f == 'h' || f == 'l' || f == 't'
# define F3(f) f == 'j' || f == 'z'
# define DD_I_OO_UU_XX_P(q) DD1(q) || DD2(q)
# define DD1(q) q == 'd' || q == 'i' || q == 'D' || q == 'o' || q == 'O'
# define DD2(q) q == 'u' || q == 'U' || q == 'x' || q == 'X' || q == 'p'
# define S_C_PCT_Z_R_USD(q, f) S1(q, f) || S2(q, f) || S3(q, f)
# define S1(q, f) (q == 's' && !ft_strchr(f, 'l'))
# define S2(q, f) (q == 'c' && !ft_strchr(f, 'l'))
# define S3(q, f) q == '%' || q == 'Z' || q == 'R'
# define Z 0
# define S 1
# define P 2
# define M 3
# define H 4
# define N 5
# define LEN (int)ft_strlen(*context)
# define NS "\0\0\0\0\0\0\0n"
# define MS "\0\0\0\0\0\0\0m"
# define NOT_PCT(q) q != '%' && q != 'Z' && q != 'R' && q != '$' && q != 'c'
# define PRECISION_HAS_BEEN_FOUND P1 P2
# define P1 *format == '.' && !(*precision = 0) &&
# define P2 (ft_isdigit(*(format + 1)) || *(format + 1) == '*') && format++
# include <stdio.h>
# include <stdarg.h>

int		digit_format_apply\
(va_list ap, char *format, char **context, char qualifier);
char	*dig_context_manager(char **context, int value, char *flags);
char	*uni_context_manager\
(int field, int uni_len, char *flags, char **context);
char	*get_context_due_to_size_specification\
(char *format, va_list ap, char qualifier);
char	*decimal_to_octal(uint64_t decimal);
char	*decimal_to_hex(unsigned long long int nbr, char qualifier);
char	*get_flags_field_precision\
(char *format, int *field, int *precision, va_list ap);
int		unicode_string(char **context, char *format, va_list ap);
int		unicode_character(char **context, char *format, va_list ap);
int		string_format_apply\
(char **context, char *format, char qualifier, va_list ap);
int		double_format_apply(char **context, char *format, va_list ap);

#endif
