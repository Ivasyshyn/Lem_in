/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_context_due_to_size_specification.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 22:21:59 by sivasysh          #+#    #+#             */
/*   Updated: 2018/03/12 22:22:00 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "printf.h"

char	get_size_specification(char *format)
{
	int quantity;

	quantity = 0;
	if (ft_strchr(format, 't') || ft_strchr(format, 'z') ||\
	ft_strchr(format, 'j'))
		return ('z');
	if (ft_strchr(format, 'l'))
	{
		while (*format++)
			if (*(format - 1) == 'l')
				quantity++;
		if (quantity % 2 == 0)
			return ('L');
		return ('l');
	}
	if (ft_strchr(format, 'h'))
	{
		while (*format++)
			if (*(format - 1) == 'h')
				quantity++;
		if (quantity % 2 == 0)
			return ('H');
		return ('h');
	}
	return (' ');
}

char	*return_o(char spec, char q, va_list ap)
{
	if (q == 'O')
	{
		if (spec == 'l')
			return (decimal_to_octal(va_arg(ap, unsigned long)));
	}
	if (q == 'o')
	{
		if (spec == 'z' || spec == 'L')
			return (decimal_to_octal(va_arg(ap, unsigned long long)));
		if (spec == 'l')
			return (decimal_to_octal(va_arg(ap, unsigned long)));
		if (spec == 'H')
			return (decimal_to_octal((unsigned char)va_arg(ap, unsigned int)));
		if (spec == 'h')
			return (decimal_to_octal((unsigned short)va_arg(ap, unsigned int)));
	}
	return (decimal_to_octal((q == 'O') ? va_arg(ap, unsigned long long) :\
	va_arg(ap, unsigned int)));
}

char	*return_u_x(char spec, char q, va_list ap)
{
	if (q == 'u')
	{
		if (spec == 'z' || spec == 'L')
			return (ft_itoa_unsigned(va_arg(ap, unsigned long long)));
		if (spec == 'l')
			return (ft_itoa_unsigned(va_arg(ap, unsigned long)));
		if (spec == 'H')
			return (ft_itoa_unsigned((unsigned char)va_arg(ap, unsigned int)));
		if (spec == 'h')
			return (ft_itoa_unsigned((unsigned short)va_arg(ap, unsigned int)));
	}
	if (q == 'x' || q == 'X')
	{
		if (spec == 'z' || spec == 'L')
			return (decimal_to_hex(va_arg(ap, unsigned long long), q));
		if (spec == 'l')
			return (decimal_to_hex(va_arg(ap, unsigned long), q));
		if (spec == 'H')
			return (decimal_to_hex((unsigned char)va_arg(ap, unsigned int), q));
		if (spec == 'h')
			return (decimal_to_hex((unsigned short)\
			va_arg(ap, unsigned int), q));
	}
	return ((q == 'u') ? ft_itoa_unsigned(va_arg(ap, unsigned int)) :\
	decimal_to_hex(va_arg(ap, unsigned int), q));
}

char	*get_context_due_to_size_specification(char *format, va_list ap,\
char qualifier)
{
	char spec;

	spec = get_size_specification(format);
	if (qualifier == 'D')
		return (ft_itoa_long(va_arg(ap, long long)));
	if (qualifier == 'U')
		return (ft_itoa_unsigned(va_arg(ap, unsigned long)));
	if (qualifier == 'p')
		return (decimal_to_hex(va_arg(ap, unsigned long long), qualifier));
	if (qualifier == 'O' || qualifier == 'o')
		return (return_o(spec, qualifier, ap));
	if (qualifier == 'u' || qualifier == 'x' || qualifier == 'X')
		return (return_u_x(spec, qualifier, ap));
	if (qualifier == 'd' || qualifier == 'i')
	{
		if (spec == 'z' || spec == 'L')
			return (ft_itoa_long(va_arg(ap, long long)));
		if (spec == 'l')
			return (ft_itoa_long(va_arg(ap, long)));
		if (spec == 'H')
			return (ft_itoa_long((char)va_arg(ap, int)));
		if (spec == 'h')
			return (ft_itoa_long((short)va_arg(ap, int)));
	}
	return (ft_itoa_long(va_arg(ap, int)));
}
