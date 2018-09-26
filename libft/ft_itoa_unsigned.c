/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 22:25:46 by sivasysh          #+#    #+#             */
/*   Updated: 2018/03/12 22:25:47 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t		ft_ch_in_nb_unsigned(unsigned long long int nb)
{
	size_t	len;

	len = 0;
	if (nb > 9)
		len += ft_ch_in_nb_unsigned(nb / 10);
	return (++len);
}

char		*ft_itoa_unsigned(unsigned long long int n)
{
	size_t	len;
	char	*new;

	len = ft_ch_in_nb_unsigned(n);
	if (!(new = ft_strnew(len)))
		return (NULL);
	while (len-- && new[len] != '-' && new[len] != '9')
	{
		new[len] = (n % 10 + '0');
		n /= 10;
	}
	return (new);
}
