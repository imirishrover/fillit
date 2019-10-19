/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsance <nsance@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 19:36:15 by nsance            #+#    #+#             */
/*   Updated: 2019/10/19 16:29:54 by nsance           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	*ft_memalloc(size_t size)
{
	void *output;

	output = 0;
	if (size)
	{
		if ((output = (void *)malloc(size)))
			ft_bzero(output, size);
	}
	return (output);
}
