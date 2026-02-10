/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexputnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adores <adores@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:52:23 by adores            #+#    #+#             */
/*   Updated: 2025/04/30 11:49:15 by adores           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexaputnbr(unsigned int i, unsigned char c)
{
	const char	*hexup = "0123456789ABCDEF";
	const char	*hexlo = "0123456789abcdef";
	int			count;

	count = 0;
	if (i > 15)
		count += ft_hexaputnbr (i / 16, c);
	if (c == 'X')
		count += ft_printchar (hexup[i % 16]);
	else if (c == 'x')
		count += ft_printchar (hexlo[i % 16]);
	return (count);
}
/*int main(void)
{
	int i = 25567;
	char c = 'X';
	ft_hexaputnbr(i , c);
	printf("\n");
	printf("\n%d", ft_hexaputnbr(i, c));
}*/