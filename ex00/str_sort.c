/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalendi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 15:24:38 by lcalendi          #+#    #+#             */
/*   Updated: 2019/08/10 16:04:18 by lcalendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*str_sort(char *str)
{
	int size;
	int i;
	int *tab;

	i = 0;
	size = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			size++;
		i++;
	}
	tab = malloc(4 * (size + 1));
	i = 0;
	tab[0] = size;
	size = 1;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			tab[size] = str[i] - '0';
			size++;
		}
		i++;
	}
	return (tab);
}
