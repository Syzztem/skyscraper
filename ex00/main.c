/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lothieve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 11:05:43 by lothieve          #+#    #+#             */
/*   Updated: 2019/08/11 17:05:15 by lcalendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		error(int code)
{
	int		size;
	char	*e_list[4];

	e_list[0] = "Error : malloc failed\n";
	e_list[1] = "Error : arg format\n";
	e_list[2] = "Error : wrong number of arguments\n";
	e_list[3] = "Error : unsolvable\n";
	size = 0;
	while (e_list[-code - 1][size])
		size++;
	write(2, e_list[-code - 1], size);
	return (-1);
}

int		main(int ac, char **av)
{
	int i;
	int var;

	if (ac == 2)
	{
		i = count_ints(av[1]);
		if (i < 4 || i % 4 != 0)
			return (error(-2));
		i /= 4;
		var = place(str_sort(av[1]), i);
		if (var < 0)
			return (error(var));
	}
	else
		return (error(-3));
}
