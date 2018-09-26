/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit_format_apply.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 22:16:45 by sivasysh          #+#    #+#             */
/*   Updated: 2018/03/12 22:16:45 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "printf.h"

void	plugin_unsigned(char **context, int precision, char q, char *flags)
{
	char	*hash;

	if ((q == 'o' || q == 'O') && flags[H])
		if (ft_atoi(*context) != 0 || precision == 0)
		{
			hash = ft_strdup("0");
			*context = ft_strjoin_modified(&hash, context);
		}
}

void	plugin_hash(char **context, char q, char *flags, int field)
{
	char	*hash;

	if ((q == 'x' || q == 'X') && flags[H])
		if ((((!flags[Z] || flags[M]) && ft_atoi_long(*context) > 0)))
		{
			if (q == 'x')
				hash = ft_strdup("0x");
			else
				hash = ft_strdup("0X");
			*context = ft_strjoin_modified(&hash, context);
		}
	if (q == 'p')
		if (field < LEN || (flags[M] || !flags[Z]))
		{
			hash = ft_strdup("0x");
			*context = ft_strjoin_modified(&hash, context);
		}
}

void	plugin_addon(char **context, int field, char q, char *flags)
{
	if (q == 'x' || q == 'X')
		if (flags[Z] && flags[H])
			*(*context + 1) = q;
	if (q == 'p')
		if (field > LEN || !(flags[M] || !flags[Z]))
			*(*context + 1) = 'x';
}

void	plugin_clear_s_and_p_flags_if_puox(char *flags, char q)
{
	if (!(q != 'p' && q != 'U' && q != 'u' && q != 'O' && q != 'o' &&\
	q != 'x' && q != 'X'))
	{
		flags[1] = '\0';
		flags[2] = '\0';
	}
}

int		digit_format_apply(va_list ap, char *format, char **context,\
char qualifier)
{
	int		field;
	int		precision;
	char	*flags;

	ft_zero_initializer(2, &field, &precision);
	flags = get_flags_field_precision(format, &field, &precision, ap);
	plugin_clear_s_and_p_flags_if_puox(flags, qualifier);
	*context = get_context_due_to_size_specification(format, ap, qualifier);
	if (ft_atoi(*context) == 0 && precision == 0)
		ft_bzero(*context, ft_strlen(*context));
	if (ft_atoi_long(*context) < 0)
		flags[N] = 'N';
	if (precision >= 0)
		flags[Z] = '\0';
	if ((precision > LEN) && flags[0] == 0)
		flags[Z] = 0;
	plugin_unsigned(context, precision, qualifier, flags);
	if (precision > LEN || (ft_atoi_long(*context) < 0 && precision > LEN - 1))
		*context = dig_context_manager(context, precision, flags[N] ? NS : MS);
	plugin_hash(context, qualifier, flags, field);
	if (((flags[S] || flags[P]) && ft_atoi_long(*context) >= 0) || field > LEN)
		*context = dig_context_manager(context, field, flags);
	plugin_addon(context, field, qualifier, flags);
	return (ft_putstr_mod(context, ft_strlen(*context)));
}
