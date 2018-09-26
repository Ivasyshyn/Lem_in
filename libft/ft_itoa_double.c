/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 18:28:40 by sivasysh          #+#    #+#             */
/*   Updated: 2018/03/13 18:28:40 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		plugin_rounding_off(char **integral, double nbr,\
double rounding_off, int precision)
{
	double	nbr_copy;
	char	*negative;

	negative = NULL;
	if (nbr < 0.0 && (nbr *= -1))
		negative = ft_strdup("-");
	nbr_copy = nbr;
	while (1 + precision--)
	{
		rounding_off /= 10;
		nbr -= (int)nbr;
		nbr *= 10.0;
	}
	nbr = ((int)nbr >= 5 && (int)nbr <= 9) ? nbr_copy + rounding_off : nbr_copy;
	if (precision != 0 && (nbr - (int)nbr) < rounding_off)
		*integral = ft_itoa_long((long long)nbr_copy + 1);
	else
		*integral = ft_itoa_long((long long)nbr_copy);
	if (negative)
		*integral = ft_strjoin_modified(&negative, integral);
	return ((nbr - (long long int)nbr));
}

void		plugin_hash_and_no_precision(char **fraction, int precision,\
char *format)
{
	if (precision == 0)
	{
		if (ft_strchr(format, '#'))
			*fraction[2] = '\0';
		else
			*fraction[0] = '\0';
	}
}

char		*ft_itoa_double(double nbr, int precision, char *format)
{
	char	*integral;
	char	*fraction;
	double	rounding_off;
	int		i;

	precision = (precision < 0) ? 6 : precision;
	fraction = ft_strnew((size_t)precision + 1);
	i = 0;
	fraction[i++] = (char)(ft_strchr(format, '\'') ? ',' : '.');
	rounding_off = 1;
	nbr = plugin_rounding_off(&integral, nbr, rounding_off, precision);
	plugin_hash_and_no_precision(&fraction, precision, format);
	while (i <= precision + 1)
	{
		nbr *= 10.0;
		fraction[i++] = (char)((int)nbr + '0');
		nbr -= (int)nbr;
	}
	if (precision > 15 && (fraction[i - 1] >= '5' && fraction[i - 1] <= '9'))
		fraction[i - 2] += 1;
	fraction[i - 1] = '\0';
	return (ft_strjoin_modified(&integral, &fraction));
}
