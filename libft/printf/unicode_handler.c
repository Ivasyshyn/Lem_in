/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 22:38:33 by sivasysh          #+#    #+#             */
/*   Updated: 2018/03/12 22:38:33 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "printf.h"

short	switch_precision(int *uni_len, short bytes, int click, int *precision)
{
	if (click && (*precision -= bytes) < 0)
		return (1);
	*uni_len += bytes;
	return (0);
}

int		get_uni_len(wchar_t *character, int precision, short click)
{
	unsigned int	nob;
	int				uni_len;

	uni_len = 0;
	while ((nob = (unsigned int)*character) && *character++)
	{
		if (nob > 0x0000 && nob <= 0x007F)
			if (switch_precision(&uni_len, 1, click, &precision))
				break ;
		if (nob >= 0x0080 && nob <= 0x07FF)
			if (switch_precision(&uni_len, 2, click, &precision))
				break ;
		if (nob >= 0x0800 && nob <= 0xFFFF)
			if (switch_precision(&uni_len, 3, click, &precision))
				break ;
		if (nob >= 0x10000 && nob <= 0x10FFFF)
			if (switch_precision(&uni_len, 4, click, &precision))
				break ;
	}
	return (uni_len);
}

void	fill_uni_string(wchar_t *character, char *context, int uni_len)
{
	unsigned int	nob;

	while (uni_len && *character && (nob = (unsigned int)*character++))
	{
		if ((nob > 0x0000 && nob <= 0x007F) && (uni_len -= 1) >= 0)
			*(context)++ = (char)nob;
		if ((nob >= 0x0080 && nob <= 0x07FF) && (uni_len -= 2) >= 0)
		{
			*(context)++ = (char)(((nob & 0x07c0) >> 6) + 0xC0);
			*(context)++ = (char)(((nob & 0x003F)) + 0x80);
		}
		if ((nob >= 0x0800 && nob <= 0xFFFF) && (uni_len -= 3) >= 0)
		{
			*(context)++ = (char)(((nob & 0xF000) >> 12) + 0xE0);
			*(context)++ = (char)(((nob & 0x0FC0) >> 6) + 0x80);
			*(context)++ = (char)(((nob & 0x003F)) + 0x80);
		}
		if ((nob >= 0x10000 && nob <= 0x10FFFF) && (uni_len -= 4) >= 0)
		{
			*(context)++ = (char)(((nob & 0x1C0000) >> 18) + 0xF0);
			*(context)++ = (char)(((nob & 0x03F000) >> 12) + 0x80);
			*(context)++ = (char)(((nob & 0x0FC0) >> 6) + 0x80);
			*(context)++ = (char)(((nob & 0x003F)) + 0x80);
		}
	}
}

int		unicode_string(char **context, char *format, va_list ap)
{
	int		field;
	int		precision;
	char	*flags;
	int		uni_len;
	wchar_t *character;

	ft_zero_initializer(2, &field, &precision);
	flags = get_flags_field_precision(format, &field, &precision, ap);
	if ((character = va_arg(ap, wchar_t*)) == NULL)
		character = L"(null)";
	uni_len = get_uni_len(character, precision, (short)(precision < 0 ? 0 : 1));
	*context = ft_strnew((size_t)uni_len);
	fill_uni_string(character, *context, uni_len);
	*context = uni_context_manager(field, uni_len, flags, context);
	return (ft_putstr_mod(context, ft_strlen(*context)));
}

int		unicode_character(char **context, char *format, va_list ap)
{
	int		field;
	int		precision;
	char	*flags;
	int		uni_len;
	wchar_t *character;

	ft_zero_initializer(2, &field, &precision);
	flags = get_flags_field_precision(format, &field, &precision, ap);
	character = (wchar_t*)malloc(sizeof(wchar_t) * 2);
	if (!(*character = va_arg(ap, wchar_t)))
		*character = L'\0';
	character[1] = 0;
	uni_len = get_uni_len(character, 0, 0);
	*context = ft_strnew((size_t)uni_len);
	fill_uni_string(character, *context, uni_len);
	if (**context == '\0' && (flags[9] = '*'))
	{
		uni_len = 1;
		**context = '*';
	}
	*context = uni_context_manager(field, uni_len, flags, context);
	if ((uni_len = LEN) && flags[9])
		*ft_strchr(*context, '*') = '\0';
	free(character);
	return (ft_putstr_mod(context, (size_t)uni_len));
}
