/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalendi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 15:24:38 by lcalendi          #+#    #+#             */
/*   Updated: 2019/08/11 14:29:46 by lcalendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_valid(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9') && i % 2 == 0)
			return (0);
		if (str[i] != ' ' && i % 2 == 1)
			return (0);
		i++;
	}
	return (1);
}

int		count_ints(char *str)
{
	int i;

	if (!is_valid(str))
		return (-2);
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
