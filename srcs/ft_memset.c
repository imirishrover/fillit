/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsance <nsance@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 20:13:28 by nsance            #+#    #+#             */
/*   Updated: 2019/10/19 16:30:03 by nsance           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*start;

	start = b;
	while (len)
	{
		*start = c;
		start++;
		len--;
	}
	return (b);
}
