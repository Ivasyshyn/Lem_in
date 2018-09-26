/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 22:25:46 by sivasysh          #+#    #+#             */
/*   Updated: 2018/03/12 22:25:47 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long		ft_atoi_long(const char *str)
{
	unsigned long	res;
	unsigned long	tres;
	int				mod;

	tres = 0;
	res = 0;
	mod = 1;
	while (ft_find_spaces(*str))
		str++;
	if (*str == '-')
		mod = -1;
	if (*str == '+' || *str == '-')
		str++;
	while ((*str >= '0') && (*str <= '9'))
	{
		tres = res * 10 + *str - '0';
		str++;
		if ((tres > 9223372036854775807 || tres < res) && mod == 1)
			return (-1);
		if ((tres > 9223372036854775807 || tres < res) && mod == -1)
			return (0);
		res = tres;
	}
	return (res *= mod);
}
