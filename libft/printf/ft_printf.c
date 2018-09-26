/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 22:44:03 by sivasysh          #+#    #+#             */
/*   Updated: 2018/03/12 22:44:03 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "printf.h"

int		skip_the_flags_if_no_qualifier(char **start, char **traverse)
{
	*traverse = *start;
	while (FLAG(*(*traverse)) || ft_isdigit(*(*traverse)))
		(*traverse)++;
	return (0);
}

int		qualifier_handler(char **traverse, va_list ap, int *total)
{
	char	*start;
	char	qualifier;
	char	*format;
	char	*context;

	start = *traverse;
	while (*(*traverse) && !(QUALIFIER(*(*traverse))))
		(*traverse)++;
	if (*(*traverse) == '\0')
		return (skip_the_flags_if_no_qualifier(&start, traverse));
	qualifier = *(*traverse)++;
	format = ft_strnew(*traverse - start);
	ft_memccpy(format, start, qualifier, ft_strlen(start));
	if (S_C_PCT_Z_R_USD(qualifier, format))
		*total += string_format_apply(&context, format, qualifier, ap);
	if (DD_I_OO_UU_XX_P(qualifier))
		*total += digit_format_apply(ap, format, &context, qualifier);
	if (qualifier == 'S' || (qualifier == 's' && ft_strchr(format, 'l')))
		*total += unicode_string(&context, format, ap);
	if (qualifier == 'C' || (qualifier == 'c' && ft_strchr(format, 'l')))
		*total += unicode_character(&context, format, ap);
	if (qualifier == 'f' || qualifier == 'F')
		*total += double_format_apply(&context, format, ap);
	ft_strdel(&format);
	return (*total);
}

int		ft_printf(char *format, ...)
{
	int		total;
	va_list	ap;

	total = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%' && ++format)
		{
			qualifier_handler(&format, ap, &total);
			continue;
		}
		if (*format && ++total)
			ft_putchar(*format++);
	}
	va_end(ap);
	return (total);
}
