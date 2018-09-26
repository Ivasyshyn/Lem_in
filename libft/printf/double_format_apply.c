/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_format_apply.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 22:47:25 by sivasysh          #+#    #+#             */
/*   Updated: 2018/03/12 22:47:25 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "printf.h"

int		double_format_apply(char **context, char *format, va_list ap)
{
	int		field;
	int		precision;
	char	*space;
	char	*flags;

	ft_zero_initializer(2, &field, &precision);
	flags = get_flags_field_precision(format, &field, &precision, ap);
	*context = ft_itoa_double(va_arg(ap, double), precision, format);
	if (field > LEN)
	{
		space = ft_strnew((size_t)(field - LEN));
		ft_memset(space, flags[Z] && !flags[M] ?\
		'0' : ' ', (size_t)(field - LEN));
		*context = flags[M] ?\
		ft_strjoin_modified(context, &space) :\
		ft_strjoin_modified(&space, context);
	}
	return (ft_putstr_mod(context, ft_strlen(*context)));
}
