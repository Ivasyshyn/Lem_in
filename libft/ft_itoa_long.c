/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 22:25:46 by sivasysh          #+#    #+#             */
/*   Updated: 2018/03/12 22:25:47 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_long(long long n)
{
	int		l;
	char	*new;

	l = ft_ch_in_nb_long(n);
	if (!(new = ft_strnew(l)))
		return (NULL);
	if (n <= LONG_MIN && (new[1] = '9'))
		n = -223372036854775808;
	if (n < 0 && (new[0] = '-'))
		n *= -1;
	while (l-- && new[l] != '-' && new[l] != '9')
	{
		new[l] = (n % 10 + '0');
		n /= 10;
	}
	return (new);
}
