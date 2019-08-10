/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lothieve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 14:25:32 by lothieve          #+#    #+#             */
/*   Updated: 2019/07/31 13:33:47 by lothieve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	a;
	unsigned long	i;

	if (nb == 0)
		ft_putchar('0');
	i = 1;
	a = nb > 0 ? nb : -nb;
	if (nb < 0)
		ft_putchar('-');
	while (i <= a)
		i *= 10;
	i /= 10;
	while (i >= 1)
	{
		ft_putchar(a / i + '0');
		a %= i;
		i /= 10;
	}
}
