/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalendi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 15:24:38 by lcalendi          #+#    #+#             */
/*   Updated: 2019/08/10 18:06:54 by lothieve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		count_ints(char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			i++;
		str++;
	}
	return (i);
}

int		*str_sort(char *str)
{
	int i;
	int *tab;

	if (!(tab = malloc(sizeof(int) * (count_ints(str)))))
		return (NULL);
	i = 0;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			tab[i] = *str - '0';
			i++;
		}
		str++;
	}
	return (tab);
}
