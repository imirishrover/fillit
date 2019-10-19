/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsance <nsance@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 20:01:38 by nsance            #+#    #+#             */
/*   Updated: 2019/10/19 16:33:32 by nsance           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

size_t	ft_strlen(const char *str)
{
	size_t counter;

	counter = 0;
	if (*str)
	{
		while (*str != '\0')
		{
			counter++;
			str++;
		}
		return (counter);
	}
	return (0);
}
