/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 17:35:43 by sivasysh          #+#    #+#             */
/*   Updated: 2017/10/30 17:35:43 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_atoi(const char *str)
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
