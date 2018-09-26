/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero_initializer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 21:45:14 by sivasysh          #+#    #+#             */
/*   Updated: 2018/03/12 21:45:14 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

void	ft_zero_initializer(int counter, ...)
{
	va_list ap;

	va_start(ap, counter);
	while (counter--)
		*va_arg(ap, int *) = 0;
	va_end(ap);
}
