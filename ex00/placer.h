/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lothieve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 11:58:48 by lothieve          #+#    #+#             */
/*   Updated: 2019/08/10 18:07:14 by lothieve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLACER_H
# define PLACER_H
# include <unistd.h>
# include <stdlib.h>

void	ft_putnbr(int nb);
int		check(int **grid, int *input, int max, int range);
int		*str_sort(char *str);

#endif
