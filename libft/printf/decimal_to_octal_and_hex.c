/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_to_octal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 22:23:20 by sivasysh          #+#    #+#             */
/*   Updated: 2018/03/12 22:23:20 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "printf.h"

void	reversed_octal_filling(uint64_t decimal, char **octal)
{
	if (decimal)
	{
		reversed_octal_filling(decimal / 8, octal);
		*(*octal)++ = (char)(decimal % 8 + '0');
	}
	else
		*(*octal) = '0';
}

char	*decimal_to_octal(uint64_t decimal)
{
	char *octal;
	char *pointer;

	octal = ft_strnew(50);
	pointer = octal;
	reversed_octal_filling(decimal, &octal);
	return (pointer);
}

char	*decimal_to_hex(unsigned long long int nbr, char qualifier)
{
	char *current;
	char *clean;
	char *result;
	char *hexes;

	if ((result = ft_strdup("")) && qualifier == 'X')
		hexes = "A\0B\0C\0D\0E\0F\0";
	else
		hexes = "a\0b\0c\0d\0e\0f\0";
	if ((long long int)(nbr % 16) >= 0 && nbr % 16 <= 9)
	{
		current = (nbr < 16) ? ft_itoa(nbr) : ft_itoa(nbr % 16);
		result = ft_strjoin_modified(&result, &current);
	}
	else
	{
		clean = result;
		result = ft_strjoin(result, &(hexes[(((nbr % 16) - 10) * 2)]));
		ft_strdel(&clean);
	}
	if (nbr / 16 > 0 && (current = decimal_to_hex(nbr / 16, qualifier)))
		result = ft_strjoin_modified(&current, &result);
	return (result);
}
