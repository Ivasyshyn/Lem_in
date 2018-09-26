/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_format_apply.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 22:42:23 by sivasysh          #+#    #+#             */
/*   Updated: 2018/03/12 22:42:23 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "printf.h"

char	*char_to_string(char b)
{
	static char array[2];

	ft_bzero(array, 2);
	array[0] = b;
	return (array);
}

char	*get_context_duo_to_qualifier(char qualifier, va_list ap)
{
	char *context;

	if (qualifier == 'c')
		context = ft_strdup(char_to_string((char)va_arg(ap, int)));
	else if (qualifier == 'Z')
		context = ft_strdup("Z");
	else if (qualifier == 'R')
		context = ft_strdup("R");
	else if (qualifier == '%')
		context = ft_strdup("%");
	else if ((context = va_arg(ap, char *)) == NULL)
		context = ft_strdup("(null)");
	else
		context = ft_strdup(context);
	return (context);
}

int		string_format_apply(char **context, char *format, char qualifier,\
va_list ap)
{
	int		field;
	int		precision;
	char	*space;
	char	*flags;
	size_t	len;

	ft_zero_initializer(2, &field, &precision);
	flags = get_flags_field_precision(format, &field, &precision, ap);
	*context = get_context_duo_to_qualifier(qualifier, ap);
	if (NOT_PCT(qualifier) && precision >= 0 && precision < LEN)
		*(*context + precision) = '\0';
	if (qualifier == 'c' && **context == '\0' && (precision = -5))
		**context = '*';
	if (field > LEN)
	{
		space = ft_strnew(field - ft_strlen(*context));
		ft_memset(space, flags[Z] && !flags[M] ? '0' : ' ', field - LEN);
		*context = flags[M] ? ft_strjoin_modified(context, &space) :\
		ft_strjoin_modified(&space, context);
	}
	len = ft_strlen(*context);
	if (precision < -1 && qualifier == 'c')
		*ft_strchr(*context, '*') = '\0';
	return (ft_putstr_mod(context, len));
}
