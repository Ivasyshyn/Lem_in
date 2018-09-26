/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 21:42:35 by sivasysh          #+#    #+#             */
/*   Updated: 2018/03/12 21:42:36 by sivasysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

void	ft_memdel_args(int counter, ...)
{
	va_list ap;

	va_start(ap, counter);
	while (counter--)
		ft_memdel(va_arg(ap, void *));
	va_end(ap);
}
