/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:40:54 by adores            #+#    #+#             */
/*   Updated: 2025/05/01 15:44:50 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(long nb)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		nb = -nb;
		i += ft_printchar('-');
	}
	if (nb >= 10)
		i += ft_printnbr(nb / 10);
	i += ft_printchar(nb % 10 + 48);
	return (i);
}
