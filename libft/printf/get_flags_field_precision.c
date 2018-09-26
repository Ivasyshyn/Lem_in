/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags_field_precision.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 22:25:46 by sivasysh          #+#    #+#             */
/*   Updated: 2018/03/12 22:25:47 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "printf.h"

int		set_either_field_or_precision(char flag, char **format, va_list ap)
{
	return (flag == '*' ? va_arg(ap, int) : ft_atoi_skip(format));
}

char	*get_flags_field_precision(char *format, int *field, int *precision,\
va_list ap)
{
	static char	flags[10];

	ft_bzero(flags, 11);
	*precision = -1;
	while (*format)
	{
		if (*format == '0' && format++ && (flags[0] = '0'))
			continue;
		if ((*format == '*' || ft_isdigit(*format)))
			*field = set_either_field_or_precision(*format, &format, ap);
		if (PRECISION_HAS_BEEN_FOUND)
			*precision = set_either_field_or_precision(*format, &format, ap);
		if (*format == ' ')
			flags[1] = ' ';
		if (*format == '+')
			flags[2] = '+';
		if (*format == '-')
			flags[3] = '-';
		if (*format == '#')
			flags[4] = '#';
		format++;
	}
	if (*field < 0 && (*field = -(*field)))
		flags[M] = '-';
	return (flags);
}
