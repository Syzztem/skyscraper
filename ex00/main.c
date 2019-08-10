/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lothieve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 11:05:43 by lothieve          #+#    #+#             */
/*   Updated: 2019/08/10 22:35:39 by lothieve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	error(void)
{
	write(2, "Error\n", 6);
	return (-1);
}

int	main(int ac, char **av)
{
	int i;

	if (ac == 2)
	{
		i = count_ints(av[1]);
		if (i % 4 != 0)
			return (error());
		i /= 4;
		if (place(str_sort(av[1]), i) == -1)
			return (error());
	}
	else
		return (error());
}
